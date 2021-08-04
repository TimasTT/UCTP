#include <QtCore>
#include <TreeFrogView>
#include "objects/timetable.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT timetable_showView : public TActionView
{
  Q_OBJECT
public:
  timetable_showView() : TActionView() { }
  QString toString();
};

QString timetable_showView::toString()
{
  responsebody.reserve(1355);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Timetable, timetable);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Timetable</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(timetable.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>TimeslotId</dt><dd>");
  responsebody += THttpUtility::htmlEscape(timetable.timeslotId());
  responsebody += QStringLiteral("</dd><br />\n<dt>AuditoryId</dt><dd>");
  responsebody += THttpUtility::htmlEscape(timetable.auditoryId());
  responsebody += QStringLiteral("</dd><br />\n<dt>BlockId</dt><dd>");
  responsebody += THttpUtility::htmlEscape(timetable.blockId());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", timetable.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(timetable_showView)

#include "timetable_showView.moc"
