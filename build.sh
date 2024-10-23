rm -rf ./build tic-tac-toe-AI
mkdir build
cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build . -j "$(find ../include ../src -name '*.cpp' | wc -l)"
mv tic-tac-toe-AI ../
cd ..