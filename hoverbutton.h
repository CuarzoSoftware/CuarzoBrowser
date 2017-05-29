#ifndef HOVERBUTTON_H
#define HOVERBUTTON_H

#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QPushButton>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

class HoverButton : public QPushButton {
	Q_OBJECT
	Q_PROPERTY(float opacityLevel READ opacityLevel WRITE setOpacityLevel)

public:

	//VARIABLES

	int w;
	int h;
	QPropertyAnimation *animation;
	QGraphicsOpacityEffect *opacity;

	//CONSTRUCTORS

	HoverButton() {
		setAttribute(Qt::WA_Hover);
		setMouseTracking(true);
		setStyleSheet("HoverButton{background:transparent;border:none;}");
		setup();
	}

	HoverButton(QIcon ico) {
		setAttribute(Qt::WA_Hover);
		setMouseTracking(true);
		setIcon(ico);
		setStyleSheet("HoverButton{background:transparent;border:none;}");
		setup();
	}

	HoverButton(QString icon, int width, int height, QString color) {
		setAttribute(Qt::WA_Hover);
		setMouseTracking(true);
		w = width;
		h = height;
		setIcon(QIcon(icon));
		setIconSize(QSize(width,height));
		setStyleSheet("HoverButton{background:transparent;border:none;}");
		setColor(color);
		setup();
	}

	HoverButton(QString icon, int width, int height) {
		setAttribute(Qt::WA_Hover);
		setMouseTracking(true);
		w = width;
		h = height;
		setIcon(QIcon(icon));
		setIconSize(QSize(width,height));
		setStyleSheet("HoverButton{background:transparent;border:none;}");
		setup();
	}

public slots:

	//METHODS

	void changeIcon(QString icon) {
		this->setIcon(QIcon(icon));
	}

	void setOpacityLevel (float level) {
		this->opacity->setOpacity((qreal)level);
	}

	float opacityLevel() {
		return 0;
	}

	void setup() {
		opacity = new QGraphicsOpacityEffect();
		opacity->setOpacity(0.1);
		opacity->setOpacity(1);
		setGraphicsEffect(opacity);
		connect(this,SIGNAL(pressed()),this,SLOT(active()));
		connect(this,SIGNAL(released()),this,SLOT(inactive()));
	}

	void active() {
		animation = new QPropertyAnimation(this, "opacityLevel");
		animation->setDuration(100);
		animation->setStartValue(1);
		animation->setEndValue(0.5);
		animation->start(QAbstractAnimation::DeleteWhenStopped);
	}

	void inactive() {
		animation = new QPropertyAnimation(this, "opacityLevel");
		animation->setDuration(100);
		animation->setStartValue(0.5);
		animation->setEndValue(1);
		animation->start(QAbstractAnimation::DeleteWhenStopped);
		connect(animation,SIGNAL(finished()),this,SLOT(reset()));
	}

	void reset() {
		this->opacity = new QGraphicsOpacityEffect();
		this->opacity->setOpacity(1);
		this->setGraphicsEffect(opacity);
	}

	void setColor(QString color) {
		QPixmap m = icon().pixmap(icon().actualSize(QSize(128, 128)));
		QPixmap newPix(m.size());
		newPix.fill( QColor(color) );
		newPix.setMask( m.createMaskFromColor( Qt::transparent ) );
		setIcon(QIcon(newPix));
	}

	void enterEvent(QEvent*) {
		setStyleSheet("HoverButton{background:#e7e7e8;border:none;}");
	}

	void leaveEvent(QEvent*) {
		setStyleSheet("HoverButton{background:transparent;border:none;}");
	}

};

#endif // HOVERBUTTON_H
