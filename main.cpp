#include <QApplication>
#include <window.h>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  a.setAttribute(Qt::AA_UseHighDpiPixmaps);
  a.setAttribute(Qt::AA_EnableHighDpiScaling);  
  BrowserWindow *window = new BrowserWindow();
  window->show();
  return a.exec();
}
