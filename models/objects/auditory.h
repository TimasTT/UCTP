#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AuditoryObject;
class QJsonArray;


class T_MODEL_EXPORT Auditory : public TAbstractModel {
public:
    Auditory();
    Auditory(const Auditory &other);
    Auditory(const AuditoryObject &object);
    ~Auditory();

    int id() const;
    QString auditoryName() const;
    void setAuditoryName(const QString &auditoryName);
    bool auditoryType() const;
    void setAuditoryType(bool auditoryType);
    Auditory &operator=(const Auditory &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Auditory create(const QString &auditoryName, bool auditoryType);
    static Auditory create(const QVariantMap &values);
    static Auditory get(int id);
    static int count();
    static QList<Auditory> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<AuditoryObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const Auditory &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, Auditory &model);
};

Q_DECLARE_METATYPE(Auditory)
Q_DECLARE_METATYPE(QList<Auditory>)

