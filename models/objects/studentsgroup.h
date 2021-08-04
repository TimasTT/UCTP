#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class StudentsGroupObject;
class QJsonArray;


class T_MODEL_EXPORT StudentsGroup : public TAbstractModel {
public:
    StudentsGroup();
    StudentsGroup(const StudentsGroup &other);
    StudentsGroup(const StudentsGroupObject &object);
    ~StudentsGroup();

    int id() const;
    QString groupName() const;
    void setGroupName(const QString &groupName);
    StudentsGroup &operator=(const StudentsGroup &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static StudentsGroup create(const QString &groupName);
    static StudentsGroup create(const QVariantMap &values);
    static StudentsGroup get(int id);
    static int count();
    static QList<StudentsGroup> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<StudentsGroupObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const StudentsGroup &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, StudentsGroup &model);
};

Q_DECLARE_METATYPE(StudentsGroup)
Q_DECLARE_METATYPE(QList<StudentsGroup>)

