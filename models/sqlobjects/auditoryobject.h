#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AuditoryObject : public TSqlObject, public QSharedData {
public:
    int id {0};
    QString auditoryName;
    bool auditoryType {false};

    enum PropertyIndex {
        Id = 0,
        AuditoryName,
        AuditoryType,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("auditory"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString auditoryName READ getauditoryName WRITE setauditoryName)
    T_DEFINE_PROPERTY(QString, auditoryName)
    Q_PROPERTY(bool auditoryType READ getauditoryType WRITE setauditoryType)
    T_DEFINE_PROPERTY(bool, auditoryType)
};

