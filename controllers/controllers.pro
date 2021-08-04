TARGET = controller
TEMPLATE = lib
CONFIG += shared x86_64
QT += network sql xml qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers ../models
DEPENDPATH  += ../helpers ../models
LIBS += -L../lib -lhelper -lmodel
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)

HEADERS += applicationcontroller.h
SOURCES += applicationcontroller.cpp
HEADERS += studentsgroupcontroller.h
SOURCES += studentsgroupcontroller.cpp
HEADERS += blockcontroller.h
SOURCES += blockcontroller.cpp
HEADERS += auditorycontroller.h
SOURCES += auditorycontroller.cpp
HEADERS += subjectcontroller.h
SOURCES += subjectcontroller.cpp
HEADERS += teachercontroller.h
SOURCES += teachercontroller.cpp
HEADERS += timeslotcontroller.h
SOURCES += timeslotcontroller.cpp
HEADERS += timetablecontroller.h
SOURCES += timetablecontroller.cpp
