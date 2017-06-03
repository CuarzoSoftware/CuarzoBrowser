#include "marcador.h"

marcador::marcador(QVariantMap map) {
	data = map;
	this->setText(data["title"].toString());
}

void marcador::mouseReleaseEvent(QMouseEvent*) {
	goToUrl(QUrl(data["url"].toString()));
}