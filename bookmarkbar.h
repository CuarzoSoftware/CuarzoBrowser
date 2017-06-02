#ifndef BOOKMARKBAR_H
#define BOOKMARKBAR_H

#include <QFrame>
#include <QHBoxLayout>
#include <QPushButton>
#include <QString>
#include <QFontMetrics>
#include <QDebug>
#include <hoverbutton.h>
#include <storage.h>

class bookmarkbar : public QFrame {

public:
	bookmarkbar();
	QHBoxLayout *bookmarks = new QHBoxLayout(this);
	HoverButton *button0 = new HoverButton();
	Storage *storage = new Storage();
};

#endif // BOOKMARKBAR_H
