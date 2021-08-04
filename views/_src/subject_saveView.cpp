#include <QtCore>
#include <TreeFrogView>
#include "objects/subject.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT subject_saveView : public TActionView
{
  Q_OBJECT
public:
  subject_saveView() : TActionView() { }
  QString toString();
};

QString subject_saveView::toString()
{
  responsebody.reserve(1667);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, subject);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Subject</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", subject["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"subject[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(subject["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>SubjectName<br /><input type=\"text\" name=\"subject[subjectName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(subject["subjectName"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>SubjectType<br /><input type=\"text\" name=\"subject[subjectType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(subject["subjectType"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", subject["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(subject_saveView)

#include "subject_saveView.moc"
