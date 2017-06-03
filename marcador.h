#ifndef MARCADOR_H
#define MARCADOR_H

#include <QVariantMap>
#include <QMouseEvent>
#include <QUrl>
#include <hoverbutton.h>

class marcador : public HoverButton {

public:
  marcador(QVariantMap);
  QVariantMap data;
  void mouseReleaseEvent(QMouseEvent *e);

signals:
	void goToUrl(QUrl);
	
};

#endif // MARCADOR_H