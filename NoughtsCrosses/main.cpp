#include "engine.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  Engine gameEngine;

  QQmlApplicationEngine engine;
  QQmlContext *context = engine.rootContext();
  context->setContextProperty("engine", &gameEngine);
  engine.load(QUrl(QLatin1String("qrc:/main.qml")));

  return app.exec();
}
