#include "auditoryservice.h"
#include "objects/auditory.h"
#include <TreeFrogModel>


void AuditoryService::index()
{
    auto auditoryList = Auditory::getAll();
    texport(auditoryList);
}

void AuditoryService::show(int id)
{
    auto auditory = Auditory::get(id);
    texport(auditory);
}

int AuditoryService::create(THttpRequest &request)
{
    auto items = request.formItems("auditory");
    auto model = Auditory::create(items);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        return -1;
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.id();
}

void AuditoryService::edit(TSession& session, int id)
{
    auto model = Auditory::get(id);
    if (!model.isNull()) {
        auto auditory = model.toVariantMap();
        texport(auditory);
    }
}

int AuditoryService::save(THttpRequest &request, TSession &session, int id)
{
    auto model = Auditory::get(id);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto auditory = request.formItems("auditory");
    model.setProperties(auditory);
    if (!model.save()) {
        texport(auditory);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool AuditoryService::remove(int id)
{
    auto auditory = Auditory::get(id);
    return auditory.remove();
}

