#include "topbar.h"

topbar::topbar() {
	container->addWidget(back_btn);
	container->addWidget(forward_btn);
	container->addWidget(reload_btn);
	container->addWidget(url_edit);
	container->addWidget(minimize_btn);
	container->addWidget(maximize_btn);
	container->addWidget(close_btn);
	container->setMargin(0);
}