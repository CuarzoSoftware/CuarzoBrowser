#include "bookmarkbar.h"

bookmarkbar::bookmarkbar() {
	bookmarks->setMargin(0);
	bookmarks->setSpacing(5);

	storage->readBookmarkJson();
	bookbar->bookmarks->insertStretch( -1, 1 );

	// test_1 = new HoverButton();
	// test_1->setText(storage->bookmarkList[0].toMap()["title"].toString());
	// bookmarks->addWidget(test_1,0,Qt::AlignLeft);
	// test_1->setFixedSize(test_1->fontMetrics().width(test_1->text())+5,30);

	// test_2 = new HoverButton();
	// test_2->setText(storage->bookmarkList[1].toMap()["title"].toString());
	// bookmarks->addWidget(test_2,0,Qt::AlignLeft);
	// test_2->setFixedSize(test_2->fontMetrics().width(test_2->text())+5,30);

	// marcadores.append(test_1);
	// marcadores.append(test_2);

	// foreach (const QPushButton &b, ArrayID)
 //    QPushButton *v = new QPushButton().setText(ArrayTitle);
 //    connect(v, SIGNAL(released()), this, SLOT(ir a ArrayURL));
}