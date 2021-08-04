#include <QtCore>
#include <TreeFrogView>
#include "objects/auditory.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT auditory_showView : public TActionView
{
  Q_OBJECT
public:
  auditory_showView() : TActionView() { }
  QString toString();
};

QString auditory_showView::toString()
{
  responsebody.reserve(1220);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Auditory, auditory);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Auditory</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(auditory.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>AuditoryName</dt><dd>");
  responsebody += THttpUtility::htmlEscape(auditory.auditoryName());
  responsebody += QStringLiteral("</dd><br />\n<dt>AuditoryType</dt><dd>");
  responsebody += THttpUtility::htmlEscape(auditory.auditoryType());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", auditory.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(auditory_showView)

#include "auditory_showView.moc"
