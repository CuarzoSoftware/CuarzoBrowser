QT += core webenginewidgets svg
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cuarzobrowser
TEMPLATE = app

HEADERS += \
  window.h \
  topbar.h \
  opbutton.h \
  bookmarkbar.h \
  hoverbutton.h \
	storage.h \
  marcador.h
SOURCES += \
  main.cpp \
  topbar.cpp \
  window.cpp \
  bookmarkbar.cpp \
  marcador.cpp

RESOURCES += \
  resources.qrc

DISTFILES += \
    .travis.yml \
    default-icon.png \
    cuarzobrowser.desktop \
    cuarzobrowser.png
