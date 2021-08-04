#include <TreeFrogModel>
#include "timeslot.h"
#include "sqlobjects/timeslotobject.h"


Timeslot::Timeslot() :
    TAbstractModel(),
    d(new TimeslotObject())
{
    // set the initial parameters
}

Timeslot::Timeslot(const Timeslot &other) :
    TAbstractModel(),
    d(other.d)
{ }

Timeslot::Timeslot(const TimeslotObject &object) :
    TAbstractModel(),
    d(new TimeslotObject(object))
{ }

Timeslot::~Timeslot()
{
    // If the reference count becomes 0,
    // the shared data object 'TimeslotObject' is deleted.
}

int Timeslot::id() const
{
    return d->id;
}

QString Timeslot::timeslotName() const
{
    return d->timeslotName;
}

void Timeslot::setTimeslotName(const QString &timeslotName)
{
    d->timeslotName = timeslotName;
}

Timeslot &Timeslot::operator=(const Timeslot &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Timeslot Timeslot::create(const QString &timeslotName)
{
    TimeslotObject obj;
    obj.timeslotName = timeslotName;
    if (!obj.create()) {
        return Timeslot();
    }
    return Timeslot(obj);
}

Timeslot Timeslot::create(const QVariantMap &values)
{
    Timeslot model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Timeslot Timeslot::get(int id)
{
    TSqlORMapper<TimeslotObject> mapper;
    return Timeslot(mapper.findByPrimaryKey(id));
}

int Timeslot::count()
{
    TSqlORMapper<TimeslotObject> mapper;
    return mapper.findCount();
}

QList<Timeslot> Timeslot::getAll()
{
    return tfGetModelListByCriteria<Timeslot, TimeslotObject>(TCriteria());
}

QJsonArray Timeslot::getAllJson(const QStringList &properties)
{
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *Timeslot::modelData()
{
    return d.data();
}

const TModelObject *Timeslot::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Timeslot &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Timeslot &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Timeslot)
