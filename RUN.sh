#!/bin/bash

echo "Building..."
/home/jlatorre/Qt/5.9/gcc_64/bin/qmake cuarzobrowser.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
echo "Running make..."
mkdir /home/jlatorre/Repos/build-cuarzobrowser-Desktop_Qt_5_9_0_GCC_64bit-Debug
make -C /home/jlatorre/Repos/build-cuarzobrowser-Desktop_Qt_5_9_0_GCC_64bit-Debug
cd /home/jlatorre/Repos/build-cuarzobrowser-Desktop_Qt_5_9_0_GCC_64bit-Debug
echo "App ready... running..."
./cuarzobrowser