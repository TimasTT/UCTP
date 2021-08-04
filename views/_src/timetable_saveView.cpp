#include <QtCore>
#include <TreeFrogView>
#include "objects/timetable.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT timetable_saveView : public TActionView
{
  Q_OBJECT
public:
  timetable_saveView() : TActionView() { }
  QString toString();
};

QString timetable_saveView::toString()
{
  responsebody.reserve(1896);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, timetable);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Timetable</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", timetable["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"timetable[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(timetable["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>TimeslotId<br /><input type=\"text\" name=\"timetable[timeslotId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(timetable["timeslotId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>AuditoryId<br /><input type=\"text\" name=\"timetable[auditoryId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(timetable["auditoryId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>BlockId<br /><input type=\"text\" name=\"timetable[blockId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(timetable["blockId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", timetable["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(timetable_saveView)

#include "timetable_saveView.moc"
