#include <QtCore>
#include <TreeFrogView>
#include "objects/block.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT block_createView : public TActionView
{
  Q_OBJECT
public:
  block_createView() : TActionView() { }
  QString toString();
};

QString block_createView::toString()
{
  responsebody.reserve(1451);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, block);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Block</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>TeacherId<br /><input name=\"block[teacherId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(block["teacherId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>SubjectId<br /><input name=\"block[subjectId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(block["subjectId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>GroupId<br /><input name=\"block[groupId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(block["groupId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(block_createView)

#include "block_createView.moc"
