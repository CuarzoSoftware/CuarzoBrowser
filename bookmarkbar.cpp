#include "bookmarkbar.h"

bookmarkbar::bookmarkbar() {
	bookmarks->setMargin(0);
	bookmarks->setSpacing(5);
	this->setContextMenuPolicy(Qt::CustomContextMenu);
	storage->readBookmarkJson();

	QList<HoverButton*> marcadores;
	HoverButton* test_1 = new HoverButton();
	test_1->setText(storage->bookmarkList[0].toMap()["title"].toString());
	bookmarks->addWidget(test_1,0,Qt::AlignLeft);
	test_1->setFixedSize(test_1->fontMetrics().width(test_1->text())+5,30);

	HoverButton* test_2 = new HoverButton();
	test_2->setText(storage->bookmarkList[1].toMap()["title"].toString());
	bookmarks->addWidget(test_2,0,Qt::AlignLeft);
	test_2->setFixedSize(test_2->fontMetrics().width(test_2->text())+5,30);

	// foreach (const QPushButton &b, ArrayID)
 //    QPushButton *v = new QPushButton().setText(ArrayTitle);
 //    connect(v, SIGNAL(released()), this, SLOT(ir a ArrayURL));
	bookmarks->insertStretch( -1, 1 );
}