#include <QtCore>
#include <TreeFrogView>
#include "objects/subject.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT subject_showView : public TActionView
{
  Q_OBJECT
public:
  subject_showView() : TActionView() { }
  QString toString();
};

QString subject_showView::toString()
{
  responsebody.reserve(1209);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Subject, subject);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Subject</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(subject.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>SubjectName</dt><dd>");
  responsebody += THttpUtility::htmlEscape(subject.subjectName());
  responsebody += QStringLiteral("</dd><br />\n<dt>SubjectType</dt><dd>");
  responsebody += THttpUtility::htmlEscape(subject.subjectType());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", subject.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(subject_showView)

#include "subject_showView.moc"
