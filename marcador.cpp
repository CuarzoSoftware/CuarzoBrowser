#include "marcador.h"

marcador::marcador(QVariant map) {
	data = map.toMap();
	this->setText(data["title"].toString());
}

void marcador::mouseReleaseEvent(QMouseEvent*) {
	goToUrl(data["url"].toUrl());
}