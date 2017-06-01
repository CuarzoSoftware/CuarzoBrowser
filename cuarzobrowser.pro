ReQT += core
QT += webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cuarzobrowser
TEMPLATE = app

HEADERS += \
	window.h \
  topbar.h \
  opbutton.h \
  bookmarkbar.h \
  hoverbutton.h \
	storage.h
SOURCES += \
  main.cpp \
  topbar.cpp \
  window.cpp \
  bookmarkbar.cpp

RESOURCES += \
  resources.qrc