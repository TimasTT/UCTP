#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TeacherObject;
class QJsonArray;


class T_MODEL_EXPORT Teacher : public TAbstractModel {
public:
    Teacher();
    Teacher(const Teacher &other);
    Teacher(const TeacherObject &object);
    ~Teacher();

    int id() const;
    QString teacherName() const;
    void setTeacherName(const QString &teacherName);
    Teacher &operator=(const Teacher &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Teacher create(const QString &teacherName);
    static Teacher create(const QVariantMap &values);
    static Teacher get(int id);
    static int count();
    static QList<Teacher> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<TeacherObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const Teacher &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, Teacher &model);
};

Q_DECLARE_METATYPE(Teacher)
Q_DECLARE_METATYPE(QList<Teacher>)

