#include "teachercontroller.h"
#include "teacherservice.h"
#include <TreeFrogController>

static TeacherService service;


void TeacherController::index()
{
    service.index();
    render();
}

void TeacherController::show(const QString &id)
{
    service.show(id.toInt());
    render();
}

void TeacherController::create()
{
    int id;

    switch (request().method()) {
    case Tf::Get:
        render();
        break;
    case Tf::Post:
        id = service.create(request());
        if (id > 0) {
            redirect(urla("show", id));
        } else {
            render();
        }
        break;

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void TeacherController::save(const QString &id)
{
    int res;

    switch (request().method()) {
    case Tf::Get:
        service.edit(session(), id.toInt());
        render();
        break;
    case Tf::Post:
        res = service.save(request(), session(), id.toInt());
        if (res > 0) {
            // Save completed
            redirect(urla("show", id));
        } else if (res < 0) {
            // Failed
            render();
        } else {
            // Retry
            redirect(urla("save", id));
        }
        break;
    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void TeacherController::remove(const QString &id)
{
    switch (request().method()) {
    case Tf::Post:
        service.remove(id.toInt());
        redirect(urla("index"));
        break;
    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

// Don't remove below this line
T_DEFINE_CONTROLLER(TeacherController)
