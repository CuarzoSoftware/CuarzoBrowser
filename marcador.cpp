#include "marcador.h"

marcador::marcador(QVariant map) {
	data = map.toMap();
	this->setText(data["title"].toString());
	this->setFixedSize(this->fontMetrics().width(this->text())+5,30);
	verificarMarcador.append(data["url"].toString());
}

void marcador::mouseReleaseEvent(QMouseEvent*) {
	goToUrl(data["url"].toUrl());
}