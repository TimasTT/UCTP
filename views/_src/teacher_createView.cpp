#include <QtCore>
#include <TreeFrogView>
#include "objects/teacher.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT teacher_createView : public TActionView
{
  Q_OBJECT
public:
  teacher_createView() : TActionView() { }
  QString toString();
};

QString teacher_createView::toString()
{
  responsebody.reserve(1073);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, teacher);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Teacher</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>TeacherName<br /><input name=\"teacher[teacherName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(teacher["teacherName"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(teacher_createView)

#include "teacher_createView.moc"
