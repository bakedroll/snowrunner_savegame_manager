#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>

#include "MainwindowContext.h"

int main(int argc, char** argv)
{
  QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
  QGuiApplication app(argc, argv);

  QQuickStyle::setStyle("Fusion");

  MainwindowContext context;

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("context", &context);
  engine.load(QUrl(QStringLiteral("qrc:/resources/mainwindow.qml")));

  return app.exec();
}
