#include <QtCore>
#include <TreeFrogView>
#include "objects/auditory.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT auditory_saveView : public TActionView
{
  Q_OBJECT
public:
  auditory_saveView() : TActionView() { }
  QString toString();
};

QString auditory_saveView::toString()
{
  responsebody.reserve(1683);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, auditory);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Auditory</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", auditory["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"auditory[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(auditory["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>AuditoryName<br /><input type=\"text\" name=\"auditory[auditoryName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(auditory["auditoryName"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>AuditoryType<br /><input type=\"text\" name=\"auditory[auditoryType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(auditory["auditoryType"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", auditory["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(auditory_saveView)

#include "auditory_saveView.moc"
