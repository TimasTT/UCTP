#include <QtCore>
#include <TreeFrogView>
#include "objects/studentsgroup.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT studentsgroup_createView : public TActionView
{
  Q_OBJECT
public:
  studentsgroup_createView() : TActionView() { }
  QString toString();
};

QString studentsgroup_createView::toString()
{
  responsebody.reserve(1092);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, studentsGroup);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Students Group</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>GroupName<br /><input name=\"studentsGroup[groupName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(studentsGroup["groupName"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(studentsgroup_createView)

#include "studentsgroup_createView.moc"
