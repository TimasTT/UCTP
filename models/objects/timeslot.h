#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TimeslotObject;
class QJsonArray;


class T_MODEL_EXPORT Timeslot : public TAbstractModel {
public:
    Timeslot();
    Timeslot(const Timeslot &other);
    Timeslot(const TimeslotObject &object);
    ~Timeslot();

    int id() const;
    QString timeslotName() const;
    void setTimeslotName(const QString &timeslotName);
    Timeslot &operator=(const Timeslot &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Timeslot create(const QString &timeslotName);
    static Timeslot create(const QVariantMap &values);
    static Timeslot get(int id);
    static int count();
    static QList<Timeslot> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<TimeslotObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const Timeslot &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, Timeslot &model);
};

Q_DECLARE_METATYPE(Timeslot)
Q_DECLARE_METATYPE(QList<Timeslot>)

