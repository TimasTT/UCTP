#include "timetableservice.h"
#include "objects/timetable.h"
#include <TreeFrogModel>


void TimetableService::index()
{
    auto timetableList = Timetable::getAll();
    texport(timetableList);
}

void TimetableService::show(int id)
{
    auto timetable = Timetable::get(id);
    texport(timetable);
}

int TimetableService::create(THttpRequest &request)
{
    auto items = request.formItems("timetable");
    auto model = Timetable::create(items);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        return -1;
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.id();
}

void TimetableService::edit(TSession& session, int id)
{
    auto model = Timetable::get(id);
    if (!model.isNull()) {
        auto timetable = model.toVariantMap();
        texport(timetable);
    }
}

int TimetableService::save(THttpRequest &request, TSession &session, int id)
{
    auto model = Timetable::get(id);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto timetable = request.formItems("timetable");
    model.setProperties(timetable);
    if (!model.save()) {
        texport(timetable);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool TimetableService::remove(int id)
{
    auto timetable = Timetable::get(id);
    return timetable.remove();
}

