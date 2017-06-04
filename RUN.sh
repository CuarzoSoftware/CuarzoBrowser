#!/bin/bash

echo "Building..."
qmake cuarzobrowser.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
echo "Running make..."
make -C /home/jlatorre/Repos/build-cuarzobrowser-Desktop_Qt_5_9_0_GCC_64bit-Debug
cd /home/jlatorre/Repos/build-cuarzobrowser-Desktop_Qt_5_9_0_GCC_64bit-Debug
echo "App ready... running..."
./cuarzobrowser