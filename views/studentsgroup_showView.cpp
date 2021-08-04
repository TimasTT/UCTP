#include <QtCore>
#include <TreeFrogView>
#include "objects/studentsgroup.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT studentsgroup_showView : public TActionView
{
  Q_OBJECT
public:
  studentsgroup_showView() : TActionView() { }
  QString toString();
};

QString studentsgroup_showView::toString()
{
  responsebody.reserve(1100);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(StudentsGroup, studentsGroup);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Students Group</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(studentsGroup.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>GroupName</dt><dd>");
  responsebody += THttpUtility::htmlEscape(studentsGroup.groupName());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", studentsGroup.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(studentsgroup_showView)

#include "studentsgroup_showView.moc"
