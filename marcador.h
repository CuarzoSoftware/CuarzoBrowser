#ifndef MARCADOR_H
#define MARCADOR_H

#include <QVariantMap>
#include <QMouseEvent>
#include <QUrl>
#include <hoverbutton.h>

class marcador : public HoverButton {
	Q_OBJECT
	
public:
  marcador(QVariantMap);
  QVariantMap data;

signals:
	void goToUrl(QUrl);

protected:
	void mouseReleaseEvent(QMouseEvent *e);
	
};

#endif // MARCADOR_H