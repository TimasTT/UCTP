#include <TreeFrogModel>
#include "studentsgroup.h"
#include "sqlobjects/studentsgroupobject.h"


StudentsGroup::StudentsGroup() :
    TAbstractModel(),
    d(new StudentsGroupObject())
{
    // set the initial parameters
}

StudentsGroup::StudentsGroup(const StudentsGroup &other) :
    TAbstractModel(),
    d(other.d)
{ }

StudentsGroup::StudentsGroup(const StudentsGroupObject &object) :
    TAbstractModel(),
    d(new StudentsGroupObject(object))
{ }

StudentsGroup::~StudentsGroup()
{
    // If the reference count becomes 0,
    // the shared data object 'StudentsGroupObject' is deleted.
}

int StudentsGroup::id() const
{
    return d->id;
}

QString StudentsGroup::groupName() const
{
    return d->groupName;
}

void StudentsGroup::setGroupName(const QString &groupName)
{
    d->groupName = groupName;
}

StudentsGroup &StudentsGroup::operator=(const StudentsGroup &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

StudentsGroup StudentsGroup::create(const QString &groupName)
{
    StudentsGroupObject obj;
    obj.groupName = groupName;
    if (!obj.create()) {
        return StudentsGroup();
    }
    return StudentsGroup(obj);
}

StudentsGroup StudentsGroup::create(const QVariantMap &values)
{
    StudentsGroup model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

StudentsGroup StudentsGroup::get(int id)
{
    TSqlORMapper<StudentsGroupObject> mapper;
    return StudentsGroup(mapper.findByPrimaryKey(id));
}

int StudentsGroup::count()
{
    TSqlORMapper<StudentsGroupObject> mapper;
    return mapper.findCount();
}

QList<StudentsGroup> StudentsGroup::getAll()
{
    return tfGetModelListByCriteria<StudentsGroup, StudentsGroupObject>(TCriteria());
}

QJsonArray StudentsGroup::getAllJson(const QStringList &properties)
{
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *StudentsGroup::modelData()
{
    return d.data();
}

const TModelObject *StudentsGroup::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const StudentsGroup &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, StudentsGroup &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(StudentsGroup)
