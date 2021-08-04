#include <QtCore>
#include <TreeFrogView>
#include "objects/teacher.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT teacher_showView : public TActionView
{
  Q_OBJECT
public:
  teacher_showView() : TActionView() { }
  QString toString();
};

QString teacher_showView::toString()
{
  responsebody.reserve(1067);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Teacher, teacher);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Teacher</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(teacher.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>TeacherName</dt><dd>");
  responsebody += THttpUtility::htmlEscape(teacher.teacherName());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", teacher.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(teacher_showView)

#include "teacher_showView.moc"
