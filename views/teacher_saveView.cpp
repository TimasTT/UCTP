#include <QtCore>
#include <TreeFrogView>
#include "objects/teacher.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT teacher_saveView : public TActionView
{
  Q_OBJECT
public:
  teacher_saveView() : TActionView() { }
  QString toString();
};

QString teacher_saveView::toString()
{
  responsebody.reserve(1444);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, teacher);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Teacher</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", teacher["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"teacher[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(teacher["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>TeacherName<br /><input type=\"text\" name=\"teacher[teacherName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(teacher["teacherName"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", teacher["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(teacher_saveView)

#include "teacher_saveView.moc"
