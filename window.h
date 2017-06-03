#ifndef BROWSERWINDOW_H
#define BROWSERWINDOW_H

#include <QDebug>
#include <QWidget>
#include <QBoxLayout>
#include <QWebEngineView>
#include <QUrl>
#include <QMouseEvent>
#include <QString>
#include <QToolTip>
#include <QCursor>
#include <QString>
#include <QPoint>
#include "topbar.h"
#include "bookmarkbar.h"
#include "storage.h"
#include "marcador.h"

class BrowserWindow : public QWidget {
  Q_OBJECT

private:
  QPoint m_pCursor;
  int progress;

public:
  BrowserWindow();
  int detectProtocol();
  QBoxLayout *container = new QBoxLayout(QBoxLayout::TopToBottom,this);
  topbar *tb = new topbar();
  bookmarkbar *bookbar = new bookmarkbar();
  QWebEngineView *view = new QWebEngineView();
  Storage *storage = new Storage();
  
public slots:
  void back_to();
  void forward_to();
  void reload_to();
  void go_to();
  void cargarMarcadores();
  void addBookmark();
  void maximize(bool checked);
  void finishLoading(bool finished);
  void setProgress(int p);
  void bookmarkRightClicked();

protected:
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
};

#endif // BROWSERWINDOW_H
