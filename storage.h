#ifndef STORAGE_H
#define STORAGE_H

#include <QFile>
#include <QObject>
#include <QVariantMap>
#include <QVariantList>
#include <QDebug>
#include <QDir>
#include <QString>
#include <QByteArray>
#include <QJsonDocument>

extern QString path;

class Storage : public QObject {
	Q_OBJECT

public:
	Storage() {detectPrefs();}
	QVariantList bookmarkList;

public slots:

	void detectPrefs() {
		if (!QDir(path).exists()) {
			QDir().mkdir(path);
		}

		if (!QDir(path+"/cuarzo").exists()) {
			QDir().mkdir(path+"/cuarzo");
		}

		if (!QDir(path+"/cuarzo/browser").exists()) {
			QDir().mkdir(path+"/cuarzo/browser");
		}

		QFileInfo check_bookmarks(path+"/cuarzo/browser/bookmarks.json");
		if (!check_bookmarks.exists()) {
			QString base = "{\"bookmarks\":[{\"id\":0,\"title\":\"Duck Duck Go\",\"url\":\"https://duckduckgo.com/\"},{\"id\":1,\"title\":\"Reddit\",\"url\":\"https://www.reddit.com/\"}]}";
			QJsonDocument doc = QJsonDocument::fromJson(base.toUtf8());
			QFile file(path+"/cuarzo/browser/bookmarks.json");
			file.open(QIODevice::WriteOnly);
			file.write(doc.toBinaryData());
			file.close();
		}
	}

	void readBookmarkJson() {
		QFile file(path+"/cuarzo/browser/bookmarks.json");
		file.open(QIODevice::ReadOnly);
		QByteArray bookmarkData = file.readAll();
		file.close();
		QJsonDocument doc = QJsonDocument::fromBinaryData(bookmarkData);
		bookmarkList = doc.toVariant().toMap()["bookmarks"].toList();
	}

	// void saveJson() {
	// 	QFile file(path+"/cuarzo/browser/bookmarks.json");
	// 	file.open(QIODevice::WriteOnly);
	// 	QJsonDocument doc = QJsonDocument::fromVariant(bookmarks);
	// 	file.write(doc.toBinaryData());
	// 	file.close();
	// }
};

#endif // STORAGE_H