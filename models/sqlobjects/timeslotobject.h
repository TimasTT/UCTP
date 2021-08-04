#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TimeslotObject : public TSqlObject, public QSharedData {
public:
    int id {0};
    QString timeslotName;

    enum PropertyIndex {
        Id = 0,
        TimeslotName,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("timeslot"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString timeslotName READ gettimeslotName WRITE settimeslotName)
    T_DEFINE_PROPERTY(QString, timeslotName)
};

