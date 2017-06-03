#ifndef BOOKMARKBAR_H
#define BOOKMARKBAR_H

#include <QFrame>
#include <QHBoxLayout>
#include <QString>
#include <QFontMetrics>
#include <QDebug>
#include <hoverbutton.h>
#include <storage.h>

class bookmarkbar : public QFrame {

public:
	bookmarkbar();
	QHBoxLayout *bookmarks = new QHBoxLayout(this);
	Storage *storage = new Storage();
	QList<HoverButton*> marcadores;
};

#endif // BOOKMARKBAR_H
