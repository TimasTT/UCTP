#include "subjectservice.h"
#include "objects/subject.h"
#include <TreeFrogModel>


void SubjectService::index()
{
    auto subjectList = Subject::getAll();
    texport(subjectList);
}

void SubjectService::show(int id)
{
    auto subject = Subject::get(id);
    texport(subject);
}

int SubjectService::create(THttpRequest &request)
{
    auto items = request.formItems("subject");
    auto model = Subject::create(items);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        return -1;
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.id();
}

void SubjectService::edit(TSession& session, int id)
{
    auto model = Subject::get(id);
    if (!model.isNull()) {
        auto subject = model.toVariantMap();
        texport(subject);
    }
}

int SubjectService::save(THttpRequest &request, TSession &session, int id)
{
    auto model = Subject::get(id);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto subject = request.formItems("subject");
    model.setProperties(subject);
    if (!model.save()) {
        texport(subject);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool SubjectService::remove(int id)
{
    auto subject = Subject::get(id);
    return subject.remove();
}

