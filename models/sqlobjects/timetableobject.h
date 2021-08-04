#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TimetableObject : public TSqlObject, public QSharedData {
public:
    int id {0};
    int timeslotId {0};
    int auditoryId {0};
    int blockId {0};

    enum PropertyIndex {
        Id = 0,
        TimeslotId,
        AuditoryId,
        BlockId,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("timetable"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int timeslotId READ gettimeslotId WRITE settimeslotId)
    T_DEFINE_PROPERTY(int, timeslotId)
    Q_PROPERTY(int auditoryId READ getauditoryId WRITE setauditoryId)
    T_DEFINE_PROPERTY(int, auditoryId)
    Q_PROPERTY(int blockId READ getblockId WRITE setblockId)
    T_DEFINE_PROPERTY(int, blockId)
};

