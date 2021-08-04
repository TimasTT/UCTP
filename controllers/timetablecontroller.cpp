#include "timetablecontroller.h"
#include "timetableservice.h"

#include <TreeFrogController>

#include <block.h>
#include <auditory.h>
#include <timeslot.h>
#include <subject.h>
#include <timetable.h>
#include <studentsgroup.h>

static TimetableService service;


void TimetableController::index() {
    service.index();
    render();
}

void TimetableController::show(const QString &id) {
    service.show(id.toInt());
    render();
}

void TimetableController::create() {
    int id;

    switch (request().method()) {
        case Tf::Get: {
            auto blockList = Block::getAll();
            auto classroomList = Auditory::getAll();
            auto timeSlotList = Timeslot::getAll();
            auto subjectsList = Subject::getAll();

            QList<Timetable> timetableList;
            Timetable::calculateTimetable(blockList, subjectsList, classroomList, timeSlotList, timetableList);
            texport(timetableList);
            redirect(urla("index"));
            break;
        }
        case Tf::Post: {

            render();
            break;
        }
        default:
            renderErrorResponse(Tf::NotFound);
            break;
    }
}

void TimetableController::save(const QString &id) {
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

void TimetableController::remove(const QString &id) {
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

void TimetableController::removeAll() {
    auto timetableList = Timetable::getAll();
    for (auto obj : timetableList) {
        obj.remove();
    }
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(TimetableController)
