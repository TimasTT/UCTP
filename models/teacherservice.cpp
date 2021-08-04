#include "teacherservice.h"
#include "objects/teacher.h"
#include <TreeFrogModel>


void TeacherService::index()
{
    auto teacherList = Teacher::getAll();
    texport(teacherList);
}

void TeacherService::show(int id)
{
    auto teacher = Teacher::get(id);
    texport(teacher);
}

int TeacherService::create(THttpRequest &request)
{
    auto items = request.formItems("teacher");
    auto model = Teacher::create(items);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        return -1;
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.id();
}

void TeacherService::edit(TSession& session, int id)
{
    auto model = Teacher::get(id);
    if (!model.isNull()) {
        auto teacher = model.toVariantMap();
        texport(teacher);
    }
}

int TeacherService::save(THttpRequest &request, TSession &session, int id)
{
    auto model = Teacher::get(id);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto teacher = request.formItems("teacher");
    model.setProperties(teacher);
    if (!model.save()) {
        texport(teacher);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool TeacherService::remove(int id)
{
    auto teacher = Teacher::get(id);
    return teacher.remove();
}

