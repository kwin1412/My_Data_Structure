set project_name=demo1

cd ./source/%project_name%
mkdir build
cd ./build
cmake -G "MinGW Makefiles" ..
make
%project_name%.exe