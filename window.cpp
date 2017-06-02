#include "window.h"

BrowserWindow::BrowserWindow() {
  almacen->readJson();
  qDebug() << almacen->bookmarks["hello"].toString();
  QString tt_http("Vulnerable Connection\nData sent between browsers and web servers is\nsent in plain text—leaving you vulnerable to eavesdropping.\nIf an attacker is able to intercept all data being sent between\na browser and a web server, they can see and use that information.");
  QString tt_https("Secure Connection\nSSL allows sensitive information such as credit card numbers, social\nsecurity numbers, and login credentials to be transmitted securely.");
  this->setWindowIcon(QIcon(":/res/images/app_icon.ico"));
  this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
  this->setMinimumSize(600,600);
  container->setContentsMargins(0,10,0,0);
  container->addWidget(tb);
  tb->setContentsMargins(5,0,5,0);
  bookbar->setContentsMargins(5,0,5,0);
  container->addWidget(bookbar);
  container->addWidget(view);
  tb->maximize_btn->setCheckable(true);
  tb->https->setVisible(false);
  tb->http->setVisible(false);
  tb->search->setVisible(true);
  connect(tb->back_btn,SIGNAL(released()),this,SLOT(back_to()));
  connect(tb->forward_btn,SIGNAL(released()),this,SLOT(forward_to()));
  connect(tb->reload_btn,SIGNAL(released()),this,SLOT(reload_to()));
  connect(tb->url_edit,SIGNAL(returnPressed()),this,SLOT(go_to()));
  connect(tb->minimize_btn,SIGNAL(released()),this,SLOT(showMinimized()));
  connect(tb->maximize_btn,SIGNAL(toggled(bool)),this,SLOT(maximize(bool)));
  connect(tb->close_btn,SIGNAL(released()),this,SLOT(close()));
  connect(tb->bookmark_action,SIGNAL(triggered()),this,SLOT(addBookmark()));
  connect(view, SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));
  connect(tb->http, &QAction::triggered, [=]{QToolTip::showText(QCursor::pos(), tt_http, this);});
  connect(tb->https, &QAction::triggered, [=]{QToolTip::showText(QCursor::pos(), tt_https, this);});
}

void BrowserWindow::setProgress(int p){Q_UNUSED(p);};

void BrowserWindow::finishLoading(bool finished) {
  if(finished){
    tb->url_edit->setText(view->url().toString());
    this->setWindowTitle(view->title());
    if (detectProtocol() == 0) {
      tb->https->setVisible(true);
      tb->http->setVisible(false);
      tb->search->setVisible(false);
    } else {
      tb->https->setVisible(false);
      tb->http->setVisible(true);
      tb->search->setVisible(false);
    }
  }
}

void BrowserWindow::back_to() {
  view->back();
}

void BrowserWindow::forward_to() {
  view->forward();
}

void BrowserWindow::reload_to() {
  view->reload();
}

void BrowserWindow::go_to() {
  if(detectProtocol() == 0 || detectProtocol() == 1) {
    view->load(QUrl(tb->url_edit->text()));
  } else {
      view->load(QUrl("http://" + tb->url_edit->text()));
  }
}

void BrowserWindow::addBookmark() {
  qDebug() << view->title();
}

void BrowserWindow::maximize(bool checked) {
  if(checked) {
    this->showMaximized();
    tb->maximize_btn->changeIcon(":/res/images/tb-maximized.svg");
  } else {
    this->showNormal();
    tb->maximize_btn->changeIcon(":/res/images/tb-maximize.svg");
  }
}

void BrowserWindow::mousePressEvent(QMouseEvent *event) {
  if(event->button() == Qt::LeftButton) {
    m_pCursor = event->globalPos() - this->geometry().topLeft();
  }
}

void BrowserWindow::mouseMoveEvent(QMouseEvent *event) {
  if(event->buttons() & Qt::LeftButton) {
    this->move(event->globalPos() - m_pCursor);
  }
}

int BrowserWindow::detectProtocol() {
  bool http = tb->url_edit->text().contains("http://");
  bool https = tb->url_edit->text().contains("https://");
  if(https == true) {
    return 0;
  } else if (http == true) {
    return 1;
  } else {
    return 2;
  }
}
