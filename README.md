# cuarzobrowser
A web browser developed with [QT](https://www.qt.io/) and [WebKit](https://webkit.org/).

# Todo

- [ ] Bookmarks
- [ ] History
- [ ] Tabs
- [ ] Private Navigation
- [ ] Settings
- [ ] Context Menu (Right Click)
- [ ] Align to Left or Right Border (Native OS)
- [ ] Sync
- [ ] Compression
- [ ] Extensions
	- [ ] uBlock Origin 
	- [ ] Privacy Badger
	- [ ] HTTPS Everywhere

# Building Instructions

In order to build QT5+ is needed.

~~~
$ git clone https://github.com/juanlatorre/cuarzobrowser.git
$ cd cuarzobrowser
$ qmake cuarzobrowser.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
$ make
$ chmod +x cuarzobrowser
$ ./cuarzobrowser
~~~

# Libraries used (ldd)

List of libraries that you may need to install, the name could variate on each Distribution.

* linux-vdso.so.1
* libQt5WebEngineWidgets.so.5
* libQt5WebEngineCore.so.5
* libQt5WebEngineCore.so.5
* libQt5Quick.so.5
* libQt5PrintSupport.so.5
* libQt5Widgets.so.5
* libQt5Gui.so.5
* libQt5WebChannel.so.5
* libQt5Qml.so.5
* libQt5Network.so.5
* libQt5Positioning.so.5
* libQt5Core.so.5
* libGL.so.1
* libpthread.so.0
* libstdc++.so.6
* libm.so.6
* libgcc_s.so.1
* libc.so.6
* libQt5QuickWidgets.so.5
* librt.so.1
* libdl.so.2
* libglib-2.0.so.0
* libfontconfig.so.1
* libfreetype.so.6
* libexpat.so.1
* libsmime3.so
* libnss3.so
* libnssutil3.so
* libnspr4.so
* libX11.so.6
* libXi.so.6
* libXext.so.6
* libXcursor.so.1
* libXfixes.so.3
* libXrender.so.1
* libXss.so.1
* libXcomposite.so.1
* libasound.so.2
* libXdamage.so.1
* libXtst.so.6
* libdbus-1.so.3
* libxml2.so.2
* libxslt.so.1
* libz.so.1
* libicui18n.so.56
* libicuuc.so.56
* libicudata.so.56
* libgthread-2.0.so.0
* libGLX.so.0
* libGLdispatch.so.0
* libpcre.so.1
* libbz2.so.1
* libpng16.so.16
* libplc4.so
* libplds4.so
* libxcb.so.1
* libsystemd.so.0
* liblzma.so.5
* libXau.so.6
* libresolv.so.2
* libselinux.so.1
* libcap.so.2
* liblz4.so.1
* libgcrypt.so.20
* libgpg-error.so.0 