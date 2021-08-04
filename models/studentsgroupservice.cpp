#include "studentsgroupservice.h"
#include "objects/studentsgroup.h"
#include <TreeFrogModel>


void StudentsGroupService::index()
{
    auto studentsGroupList = StudentsGroup::getAll();
    texport(studentsGroupList);
}

void StudentsGroupService::show(int id)
{
    auto studentsGroup = StudentsGroup::get(id);
    texport(studentsGroup);
}

int StudentsGroupService::create(THttpRequest &request)
{
    auto items = request.formItems("studentsGroup");
    auto model = StudentsGroup::create(items);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        return -1;
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.id();
}

void StudentsGroupService::edit(TSession& session, int id)
{
    auto model = StudentsGroup::get(id);
    if (!model.isNull()) {
        auto studentsGroup = model.toVariantMap();
        texport(studentsGroup);
    }
}

int StudentsGroupService::save(THttpRequest &request, TSession &session, int id)
{
    auto model = StudentsGroup::get(id);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto studentsGroup = request.formItems("studentsGroup");
    model.setProperties(studentsGroup);
    if (!model.save()) {
        texport(studentsGroup);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool StudentsGroupService::remove(int id)
{
    auto studentsGroup = StudentsGroup::get(id);
    return studentsGroup.remove();
}

