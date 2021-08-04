#include <TreeFrogModel>

#include <geneticTransformations.hpp>
#include <geneticStructure.hpp>

#include "timetable.h"
#include "sqlobjects/timetableobject.h"

Timetable::Timetable()
        : TAbstractModel(), d(new TimetableObject()) {
    // set the initial parameters
}

Timetable::Timetable(const Timetable &other)
        : TAbstractModel(), d(other.d) {}

Timetable::Timetable(const TimetableObject &object)
        : TAbstractModel(), d(new TimetableObject(object)) {}

Timetable::~Timetable() {
    // If the reference count becomes 0,
    // the shared data object 'TimetableObject' is deleted.
}

int Timetable::id() const {
    return d->id;
}

int Timetable::timeslotId() const {
    return d->timeslotId;
}

void Timetable::setTimeslotId(int timeslotId) {
    d->timeslotId = timeslotId;
}

int Timetable::auditoryId() const {
    return d->auditoryId;
}

void Timetable::setAuditoryId(int auditoryId) {
    d->auditoryId = auditoryId;
}

int Timetable::blockId() const {
    return d->blockId;
}

void Timetable::setBlockId(int blockId) {
    d->blockId = blockId;
}

Timetable &Timetable::operator=(const Timetable &other) {
    d = other.d;  // increments the reference count of the data
    return *this;
}

Timetable Timetable::create(int timeslotId, int auditoryId, int blockId) {
    TimetableObject obj;
    obj.timeslotId = timeslotId;
    obj.auditoryId = auditoryId;
    obj.blockId = blockId;
    if (!obj.create()) {
        return Timetable();
    }
    return Timetable(obj);
}

Timetable Timetable::create(const QVariantMap &values) {
    Timetable model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

void Timetable::calculateTimetable(const QList<Block> &blocks, const QList<Subject> &subjects, const QList<Auditory> &auditories,
                                   const QList<Timeslot> &timeSlots, QList<Timetable> &result) {
    std::vector<genalg::Block> blocks_;
    std::vector<int> AuditoryType1;
    std::vector<int> AuditoryType2;
    std::vector<int> AllTimes;

    std::map<int, int> subjectTypeMap;
    for (auto &subject : subjects) {
        subjectTypeMap[subject.id()] = subject.subjectType();
    }

    for (auto &block : blocks) {
        blocks_.emplace_back(block.id(), block.groupId(), block.subjectId(), subjectTypeMap[block.subjectId()], block.teacherId());
    }

    for (auto &auditory : auditories) {
        if (auditory.auditoryType() == 0)
            AuditoryType1.emplace_back(auditory.id());
        else if (auditory.auditoryType() == 1)
            AuditoryType2.emplace_back(auditory.id());
    }
    for (auto &timeSlot : timeSlots) {
        AllTimes.emplace_back(timeSlot.id());
    }

    std::shared_ptr<genalg::Population> Population = std::make_shared<genalg::Population>(blocks_, AuditoryType1, AuditoryType2, AllTimes);

    std::shared_ptr<genalg::PopulationObserver> populationObserver = std::make_shared<genalg::PopulationObserver>();

    genalg::PopulationTransformation(std::move(Population), populationObserver).populationIterate();
    std::vector<genalg::Gen> time(populationObserver->getChromosomeTime());
    std::vector<genalg::Gen> auditory(populationObserver->getChromosomeAuditory());

    for (int i = 0; i < blocks.length(); i++) {
        TimetableObject obj = TimetableObject();
        obj.auditoryId = auditory[i].getValue();
        obj.timeslotId = time[i].getValue();
        obj.blockId = blocks_[i].blockId;
        if (obj.create()) {
            result.append(Timetable(obj));
        }
    }
}

Timetable Timetable::get(int id) {
    TSqlORMapper<TimetableObject> mapper;
    return Timetable(mapper.findByPrimaryKey(id));
}

int Timetable::count() {
    TSqlORMapper<TimetableObject> mapper;
    return mapper.findCount();
}

QList<Timetable> Timetable::getAll() {
    return tfGetModelListByCriteria<Timetable, TimetableObject>(TCriteria());
}

QJsonArray Timetable::getAllJson(const QStringList &properties) {
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject* Timetable::modelData() {
    return d.data();
}

const TModelObject* Timetable::modelData() const {
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Timetable &model) {
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Timetable &model) {
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Timetable)
