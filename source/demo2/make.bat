set project_name=demo2

mkdir build
cd ./build
cmake -G "MinGW Makefiles" ..
make
%project_name%.exe

cd ..