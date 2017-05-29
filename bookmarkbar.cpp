#include <QDebug>
#include <QString>
#include <QFontMetrics>
#include "bookmarkbar.h"

bookmarkbar::bookmarkbar() {
	bookmarks->setMargin(0);
	bookmarks->setSpacing(5);

	this->setContextMenuPolicy(Qt::CustomContextMenu);

	QFontMetrics fm0(button0->fontMetrics());

	button0->setText("Marcador 1");

	QString btn0(button0->text());;

	int ancho0 = fm0.width(btn0);

	button0->setFixedSize(ancho0+5,30);

	bookmarks->addWidget(button0,0,Qt::AlignLeft);
	bookmarks->insertStretch( -1, 1 );
}