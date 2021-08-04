#include <QtCore>
#include <TreeFrogView>
#include "objects/block.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT block_showView : public TActionView
{
  Q_OBJECT
public:
  block_showView() : TActionView() { }
  QString toString();
};

QString block_showView::toString()
{
  responsebody.reserve(1319);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Block, block);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Block</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(block.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>TeacherId</dt><dd>");
  responsebody += THttpUtility::htmlEscape(block.teacherId());
  responsebody += QStringLiteral("</dd><br />\n<dt>SubjectId</dt><dd>");
  responsebody += THttpUtility::htmlEscape(block.subjectId());
  responsebody += QStringLiteral("</dd><br />\n<dt>GroupId</dt><dd>");
  responsebody += THttpUtility::htmlEscape(block.groupId());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", block.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(block_showView)

#include "block_showView.moc"
