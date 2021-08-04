#include <TreeFrogModel>
#include "auditory.h"
#include "sqlobjects/auditoryobject.h"


Auditory::Auditory() :
    TAbstractModel(),
    d(new AuditoryObject())
{
    // set the initial parameters
}

Auditory::Auditory(const Auditory &other) :
    TAbstractModel(),
    d(other.d)
{ }

Auditory::Auditory(const AuditoryObject &object) :
    TAbstractModel(),
    d(new AuditoryObject(object))
{ }

Auditory::~Auditory()
{
    // If the reference count becomes 0,
    // the shared data object 'AuditoryObject' is deleted.
}

int Auditory::id() const
{
    return d->id;
}

QString Auditory::auditoryName() const
{
    return d->auditoryName;
}

void Auditory::setAuditoryName(const QString &auditoryName)
{
    d->auditoryName = auditoryName;
}

bool Auditory::auditoryType() const
{
    return d->auditoryType;
}

void Auditory::setAuditoryType(bool auditoryType)
{
    d->auditoryType = auditoryType;
}

Auditory &Auditory::operator=(const Auditory &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Auditory Auditory::create(const QString &auditoryName, bool auditoryType)
{
    AuditoryObject obj;
    obj.auditoryName = auditoryName;
    obj.auditoryType = auditoryType;
    if (!obj.create()) {
        return Auditory();
    }
    return Auditory(obj);
}

Auditory Auditory::create(const QVariantMap &values)
{
    Auditory model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Auditory Auditory::get(int id)
{
    TSqlORMapper<AuditoryObject> mapper;
    return Auditory(mapper.findByPrimaryKey(id));
}

int Auditory::count()
{
    TSqlORMapper<AuditoryObject> mapper;
    return mapper.findCount();
}

QList<Auditory> Auditory::getAll()
{
    return tfGetModelListByCriteria<Auditory, AuditoryObject>(TCriteria());
}

QJsonArray Auditory::getAllJson(const QStringList &properties)
{
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *Auditory::modelData()
{
    return d.data();
}

const TModelObject *Auditory::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Auditory &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Auditory &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Auditory)
