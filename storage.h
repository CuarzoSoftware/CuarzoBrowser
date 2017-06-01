#ifndef STORAGE_H
#define STORAGE_H

#include <QFile>
#include <QObject>
#include <QJsonDocument>
#include <QVariantMap>
#include <QDebug>
#include <QDir>

extern QString path;

class Storage : public QObject {
	Q_OBJECT

public:
	Storage() {detectPrefs();}
	QVariantMap bookmarks;

public slots:

	void detectPrefs() {
		if (!QDir(path).exists()) {
			QDir().mkdir(path);
		}

		if (!QDir(path+"/browser").exists()) {
			QDir().mkdir(path+"/browser");
		}

		// QFileInfo bookmarks_file(path+"/browser/bookmarks.json");
		// if (!bookmarks_file.exists()) {
		// 	QString base = "{\"artists\":{},\"playlists\":{}}";
		// 	//saveJson();
		// }

		readJson();
	}

	void readJson() {
		QFile file("/tmp/bookmarks.json");
		file.open(QIODevice::ReadOnly);
		QJsonDocument doc = QJsonDocument::fromBinaryData(file.readAll());
		bookmarks = doc.toVariant().toMap();
		file.close();
	}

	void saveJson() {
		QFile file(path+"/browser/bookmarks.json");
		file.open(QIODevice::WriteOnly);
		QJsonDocument doc = QJsonDocument::fromVariant(bookmarks);
		file.write(doc.toBinaryData());
		file.close();
	}
};

#endif // STORAGE_H