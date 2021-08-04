#include "timeslotservice.h"
#include "objects/timeslot.h"
#include <TreeFrogModel>


void TimeslotService::index()
{
    auto timeslotList = Timeslot::getAll();
    texport(timeslotList);
}

void TimeslotService::show(int id)
{
    auto timeslot = Timeslot::get(id);
    texport(timeslot);
}

int TimeslotService::create(THttpRequest &request)
{
    auto items = request.formItems("timeslot");
    auto model = Timeslot::create(items);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        return -1;
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.id();
}

void TimeslotService::edit(TSession& session, int id)
{
    auto model = Timeslot::get(id);
    if (!model.isNull()) {
        auto timeslot = model.toVariantMap();
        texport(timeslot);
    }
}

int TimeslotService::save(THttpRequest &request, TSession &session, int id)
{
    auto model = Timeslot::get(id);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto timeslot = request.formItems("timeslot");
    model.setProperties(timeslot);
    if (!model.save()) {
        texport(timeslot);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool TimeslotService::remove(int id)
{
    auto timeslot = Timeslot::get(id);
    return timeslot.remove();
}

