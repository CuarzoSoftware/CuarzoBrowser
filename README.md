# cuarzobrowser
A web browser developed with [QT](https://www.qt.io/) and [WebKit](https://webkit.org/).

![Screenshot running on Fedora 25 Wayland](screenshot.png)

# Todo

- [X] Bookmarks
- [ ] History
- [ ] Tabs
- [ ] Private Navigation
- [ ] Settings
- [X] Context Menu (Right Click)
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

* Qt 5.9
* Qt Web Engine (libQt5WebEngineCore)