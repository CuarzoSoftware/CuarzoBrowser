#ifndef BOOKMARKBAR_H
#define BOOKMARKBAR_H

#include <QFrame>
#include <QHBoxLayout>
#include <QPushButton>
#include <hoverbutton.h>

class bookmarkbar : public QFrame {

public:
	bookmarkbar();
	QHBoxLayout *bookmarks = new QHBoxLayout(this);
	HoverButton *button0 = new HoverButton();
};

#endif // BOOKMARKBAR_H
