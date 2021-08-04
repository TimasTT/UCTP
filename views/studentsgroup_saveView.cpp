#include <QtCore>
#include <TreeFrogView>
#include "objects/studentsgroup.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT studentsgroup_saveView : public TActionView
{
  Q_OBJECT
public:
  studentsgroup_saveView() : TActionView() { }
  QString toString();
};

QString studentsgroup_saveView::toString()
{
  responsebody.reserve(1487);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, studentsGroup);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Students Group</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", studentsGroup["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"studentsGroup[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(studentsGroup["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>GroupName<br /><input type=\"text\" name=\"studentsGroup[groupName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(studentsGroup["groupName"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", studentsGroup["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(studentsgroup_saveView)

#include "studentsgroup_saveView.moc"
