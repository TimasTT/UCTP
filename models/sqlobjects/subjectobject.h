#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SubjectObject : public TSqlObject, public QSharedData {
public:
    int id {0};
    QString subjectName;
    bool subjectType {false};

    enum PropertyIndex {
        Id = 0,
        SubjectName,
        SubjectType,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("subject"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString subjectName READ getsubjectName WRITE setsubjectName)
    T_DEFINE_PROPERTY(QString, subjectName)
    Q_PROPERTY(bool subjectType READ getsubjectType WRITE setsubjectType)
    T_DEFINE_PROPERTY(bool, subjectType)
};

