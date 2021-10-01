set project_name=demo1

mkdir build
cd ./build
cmake -G "MinGW Makefiles" ..
make
%project_name%.exe

cd ..