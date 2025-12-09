@echo off
if not exist "build/" mkdir build
cd build
cmake .. -GNinja -DRAYGPU_BUILD_SHARED_LIBRARY=ON -DSUPPORT_GLFW=ON -DSUPPORT_WGPU_BACKEND=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_FLAGS="-msse3" -DCMAKE_CXX_FLAGS="-msse3"

cmake --build . --config Release
cd ..
