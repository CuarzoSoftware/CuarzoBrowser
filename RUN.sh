#!/bin/bash

echo "Running qmake..."
qmake-qt5 cuarzobrowser.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
echo "Running make..."
make -C /home/jlatorre/Repos/build-cuarzobrowser-Qt_5_8_Develop_Kit-Debug
cd /home/jlatorre/Repos/build-cuarzobrowser-Qt_5_8_Develop_Kit-Debug
echo "Setting permissions..."
chmod a+x cuarzobrowser
echo "App ready... running..."
./cuarzobrowser
