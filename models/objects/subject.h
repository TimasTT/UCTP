#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SubjectObject;
class QJsonArray;


class T_MODEL_EXPORT Subject : public TAbstractModel {
public:
    Subject();
    Subject(const Subject &other);
    Subject(const SubjectObject &object);
    ~Subject();

    int id() const;
    QString subjectName() const;
    void setSubjectName(const QString &subjectName);
    bool subjectType() const;
    void setSubjectType(bool subjectType);
    Subject &operator=(const Subject &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Subject create(const QString &subjectName, bool subjectType);
    static Subject create(const QVariantMap &values);
    static Subject get(int id);
    static int count();
    static QList<Subject> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<SubjectObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const Subject &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, Subject &model);
};

Q_DECLARE_METATYPE(Subject)
Q_DECLARE_METATYPE(QList<Subject>)

