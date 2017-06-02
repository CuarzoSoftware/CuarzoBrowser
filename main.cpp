#include <QApplication>
#include <QDir>
#include <window.h>

QString path = QDir::homePath() + "/.prefs";

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  a.setAttribute(Qt::AA_UseHighDpiPixmaps);
  a.setAttribute(Qt::AA_EnableHighDpiScaling);  
  a.setQuitOnLastWindowClosed(true);

  BrowserWindow *window = new BrowserWindow();
  window->show();

  return a.exec();
}
