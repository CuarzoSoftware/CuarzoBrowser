#ifndef TOPBAR_H
#define TOPBAR_H

#include <QFrame>
#include <QBoxLayout>
#include <QLineEdit>
#include <QAction>
#include <opbutton.h>

class topbar : public QFrame {

public:
	topbar();
	QBoxLayout *container = new QBoxLayout(QBoxLayout::LeftToRight,this);
	OpButton *back_btn = new OpButton(":/res/images/tb-back.svg",20,20);
	OpButton *forward_btn = new OpButton(":/res/images/tb-forward.svg",20,20);
	OpButton *reload_btn = new OpButton(":/res/images/tb-reload.svg",20,20);
	QLineEdit *url_edit = new QLineEdit(this);
	QAction *bookmark_action = url_edit->addAction(QIcon(":/res/images/tb-bookmark0.svg"), QLineEdit::TrailingPosition);
	QAction *https = url_edit->addAction(QIcon(":/res/images/tb-https.svg"), QLineEdit::LeadingPosition);
	QAction *http = url_edit->addAction(QIcon(":/res/images/tb-http.svg"), QLineEdit::LeadingPosition);
	QAction *search = url_edit->addAction(QIcon(":/res/images/tb-search.svg"), QLineEdit::LeadingPosition);
};

#endif // TOPBAR_H
