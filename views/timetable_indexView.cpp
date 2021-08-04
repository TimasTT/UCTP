#include <QtCore>
#include <TreeFrogView>
#include "objects/timetable.h" 
#include "objects/timeslot.h" 
#include "objects/auditory.h" 
#include "objects/studentsgroup.h" 
#include "objects/teacher.h" 
#include "objects/subject.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT timetable_indexView : public TActionView
{
  Q_OBJECT
public:
  timetable_indexView() : TActionView() { }
  QString toString();
};

QString timetable_indexView::toString()
{
  responsebody.reserve(1876);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
              responsebody += QStringLiteral("\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<h1>Listing Timetable</h1>\n\n");
  responsebody += QVariant(linkTo("Create a new Timetable", urla("create"))).toString();
  responsebody += QStringLiteral("<br />\n");
  responsebody += QVariant(linkTo("Remove Timetable", urla("removeAll"), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>ID</th>\n    <th>TimeslotId</th>\n    <th>AuditoryId</th>\n    <th>BlockId</th>\n  </tr>\n");
  tfetch(QList<Timetable>, timetableList);
  tfetch(QList<Timeslot>, timeSlots);
  tfetch(QList<Auditory>, auditories);
  tfetch(QList<StudentsGroup>, groups);
  tfetch(QList<Teacher>, teachers);
  tfetch(QList<Subject>, subjects);
  foreach (Timetable tt, timetableList) {
  responsebody += QStringLiteral("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(tt.id());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(tt.timeslotId());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(tt.auditoryId());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(tt.blockId());
  responsebody += QStringLiteral("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", tt.id()))).toString();
  responsebody += QStringLiteral("\n    </td>\n  </tr>\n");
  };
  responsebody += QStringLiteral("</table>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(timetable_indexView)

#include "timetable_indexView.moc"
