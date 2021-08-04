#include <QtCore>
#include <TreeFrogView>
#include "objects/timeslot.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT timeslot_showView : public TActionView
{
  Q_OBJECT
public:
  timeslot_showView() : TActionView() { }
  QString toString();
};

QString timeslot_showView::toString()
{
  responsebody.reserve(1075);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Timeslot, timeslot);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Timeslot</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(timeslot.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>TimeslotName</dt><dd>");
  responsebody += THttpUtility::htmlEscape(timeslot.timeslotName());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", timeslot.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(timeslot_showView)

#include "timeslot_showView.moc"
