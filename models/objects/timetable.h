#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TimetableObject;
class QJsonArray;


class T_MODEL_EXPORT Timetable : public TAbstractModel {
public:
    Timetable();
    Timetable(const Timetable &other);
    Timetable(const TimetableObject &object);
    ~Timetable();

    int id() const;
    int timeslotId() const;
    void setTimeslotId(int timeslotId);
    int auditoryId() const;
    void setAuditoryId(int auditoryId);
    int blockId() const;
    void setBlockId(int blockId);
    Timetable &operator=(const Timetable &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Timetable create(int timeslotId, int auditoryId, int blockId);
    static Timetable create(const QVariantMap &values);
    static Timetable get(int id);
    static int count();
    static QList<Timetable> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<TimetableObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const Timetable &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, Timetable &model);
};

Q_DECLARE_METATYPE(Timetable)
Q_DECLARE_METATYPE(QList<Timetable>)

