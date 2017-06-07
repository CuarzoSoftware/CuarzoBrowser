#include "topbar.h"

topbar::topbar() {
	container->addWidget(back_btn);
	container->addWidget(forward_btn);
	container->addWidget(reload_btn);
	container->addWidget(url_edit);
	container->setMargin(0);
}