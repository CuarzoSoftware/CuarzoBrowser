#ifndef STORAGE_H
#define STORAGE_H

#include <QFile>
#include <QObject>
#include <QJsonDocument>
#include <QVariantMap>
#include <QDebug>

class Storage : public QObject {
  Q_OBJECT

public:
  Storage();
	QVariantMap bookmarks;

public slots:
	void readJson() {
		QFile file("bookmarks.json");
		file.open(QIODevice::ReadOnly);
		QJsonDocument doc = QJsonDocument::fromBinaryData(file.readAll());
		bookmarks = doc.toVariant().toMap();
		//qDebug() << bookmarks["saca"].toString();
		file.close();
	}

	void saveJson() {
		QFile file("bookmarks.json");
		file.open(QIODevice::WriteOnly);
		QJsonDocument doc = QJsonDocument::fromVariant(bookmarks);
		file.write(doc.toBinaryData());
		file.close();
	}
};

#endif // STORAGE_H