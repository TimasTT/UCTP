#include <QtCore>
#include <TreeFrogView>
#include "objects/timetable.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT timetable_createView : public TActionView
{
  Q_OBJECT
public:
  timetable_createView() : TActionView() { }
  QString toString();
};

QString timetable_createView::toString()
{
  responsebody.reserve(1489);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, timetable);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Timetable</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>TimeslotId<br /><input name=\"timetable[timeslotId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(timetable["timeslotId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>AuditoryId<br /><input name=\"timetable[auditoryId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(timetable["auditoryId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>BlockId<br /><input name=\"timetable[blockId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(timetable["blockId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(timetable_createView)

#include "timetable_createView.moc"
