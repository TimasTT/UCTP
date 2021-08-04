#include <QtCore>
#include <TreeFrogView>
#include "objects/auditory.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT auditory_createView : public TActionView
{
  Q_OBJECT
public:
  auditory_createView() : TActionView() { }
  QString toString();
};

QString auditory_createView::toString()
{
  responsebody.reserve(1294);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, auditory);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Auditory</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>AuditoryName<br /><input name=\"auditory[auditoryName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(auditory["auditoryName"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>AuditoryType<br /><input name=\"auditory[auditoryType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(auditory["auditoryType"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(auditory_createView)

#include "auditory_createView.moc"
