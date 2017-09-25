rm -r build
mkdir build
cd ./build
cmake ..
make -j4
cd ../
mkdir output
cd ./run
