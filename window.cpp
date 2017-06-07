#include "window.h"

BrowserWindow::BrowserWindow() {
	storage->readBookmarkJson();

	cargarMarcadores();

  QString tt_http("Vulnerable Connection\nData sent between browsers and web servers is\nsent in plain text—leaving you vulnerable to eavesdropping.\nIf an attacker is able to intercept all data being sent between\na browser and a web server, they can see and use that information.");
  QString tt_https("Secure Connection\nSSL allows sensitive information such as credit card numbers, social\nsecurity numbers, and login credentials to be transmitted securely.");

  this->setWindowIcon(QIcon(":/res/images/app_icon.ico"));
  this->setMinimumSize(600,600);

  container->setContentsMargins(0,10,0,0);
  container->addWidget(tb);
  container->addWidget(bookbar);
  container->addWidget(view);

  tb->setContentsMargins(5,0,5,0);
  tb->https->setVisible(false);
  tb->http->setVisible(false);
  tb->search->setVisible(true);

  bookbar->setContentsMargins(5,0,5,0);

  connect(tb->back_btn,SIGNAL(released()),this,SLOT(back_to()));
  connect(tb->forward_btn,SIGNAL(released()),this,SLOT(forward_to()));
  connect(tb->reload_btn,SIGNAL(released()),this,SLOT(reload_to()));
  connect(tb->url_edit,SIGNAL(returnPressed()),this,SLOT(go_to()));
  connect(tb->bookmark_action,SIGNAL(triggered()),this,SLOT(agregarMarcador()));
  connect(tb->http, &QAction::triggered, [=]{QToolTip::showText(QCursor::pos(), tt_http, this);});
  connect(tb->https, &QAction::triggered, [=]{QToolTip::showText(QCursor::pos(), tt_https, this);});
  connect(view, SIGNAL(loadFinished(bool)),this, SLOT(finishLoading(bool)));
  //connect(bookbar->test_1, SIGNAL(rightClicked()),this, SLOT(bookmarkRightClicked()));
}

void BrowserWindow::cargarMarcadores() {
	foreach(QVariant map, storage->bookmarkList) {
		marcador *newMkr = new marcador(map);
		bookbar->bookmarks->addWidget(newMkr,0);
		bookbar->marcadores.append(newMkr);
		connect(newMkr,SIGNAL(goToUrl(QUrl)),this,SLOT(load(QUrl)));
	}
	bookbar->bookmarks->addStretch(1);
}	

void BrowserWindow::agregarMarcador() {
	if (!view->title().isEmpty()) {
		QString title = view->title();
		QString uri = view->url().toString();
		int pos = bookbar->bookmarks->count() - 1;
		HoverButton* marcador = new HoverButton(title);
		marcador->setFixedSize(marcador->fontMetrics().width(marcador->text())+5,30);
		bookbar->bookmarks->insertWidget(pos, marcador);
		verificarMarcador.append(uri);
		verificacionMarcadores();
	}
}

void BrowserWindow::verificacionMarcadores() {
	if (verificarMarcador.contains(view->url().toString())) {
    	tb->bookmark_action->setIcon(QIcon(":/res/images/tb-bookmark1.svg"));
			tb->bookmark_action->setEnabled(false);
    } else {
    	tb->bookmark_action->setIcon(QIcon(":/res/images/tb-bookmark0.svg"));
			tb->bookmark_action->setEnabled(true);
    }
}

void BrowserWindow::bookmarkRightClicked() {
	qDebug() << "A bookmark has been right clicked";
}

void BrowserWindow::setProgress(int p){Q_UNUSED(p);}

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
    verificacionMarcadores();
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

void BrowserWindow::load(QUrl uri) {
	view->load(uri);
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
