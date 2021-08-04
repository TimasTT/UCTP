#include <QtCore>
#include <TreeFrogView>
#include "objects/timeslot.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT timeslot_createView : public TActionView
{
  Q_OBJECT
public:
  timeslot_createView() : TActionView() { }
  QString toString();
};

QString timeslot_createView::toString()
{
  responsebody.reserve(1080);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, timeslot);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Timeslot</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>TimeslotName<br /><input name=\"timeslot[timeslotName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(timeslot["timeslotName"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(timeslot_createView)

#include "timeslot_createView.moc"
