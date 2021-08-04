#include <QtCore>
#include <TreeFrogView>
#include "objects/timeslot.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT timeslot_saveView : public TActionView
{
  Q_OBJECT
public:
  timeslot_saveView() : TActionView() { }
  QString toString();
};

QString timeslot_saveView::toString()
{
  responsebody.reserve(1455);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, timeslot);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Timeslot</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", timeslot["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"timeslot[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(timeslot["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>TimeslotName<br /><input type=\"text\" name=\"timeslot[timeslotName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(timeslot["timeslotName"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", timeslot["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(timeslot_saveView)

#include "timeslot_saveView.moc"
