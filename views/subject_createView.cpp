#include <QtCore>
#include <TreeFrogView>
#include "objects/subject.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT subject_createView : public TActionView
{
  Q_OBJECT
public:
  subject_createView() : TActionView() { }
  QString toString();
};

QString subject_createView::toString()
{
  responsebody.reserve(1282);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, subject);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Subject</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>SubjectName<br /><input name=\"subject[subjectName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(subject["subjectName"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>SubjectType<br /><input name=\"subject[subjectType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(subject["subjectType"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(subject_createView)

#include "subject_createView.moc"
