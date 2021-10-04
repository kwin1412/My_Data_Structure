set project_name=demo4

mkdir build
cd ./build
cmake -G "MinGW Makefiles" ..
make
%project_name%.exe

cd ..