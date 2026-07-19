flag=$1
test_target=$2
for last; do true; done

# Build with clang/clang++ so the compiler matches the clangd IDE analyzer.
CC="-D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++"
CC=""

debug_opt=""

if [ "$flag" = "debug" ]; then
    debug_opt="-D CMAKE_BUILD_TYPE=Debug"
fi

cmake ${debug_opt} ${CC} .
make 

if [ "$flag" = "test" ]; then
    target = ''
    if [ "$test_target" != "clean" ]; then
        target="-R ^$test_target"
    fi
    ctest -C Debug -T test --output-on-failure $target
else 
    ./bin/data_structure_and_algorithm_cpp
fi

if [ "$last" = "clean" ]; then
    rm -rf ./bin/
    rm -rf ./build/
    rm -rf ./Testing/
    rm -rf ./CMakeFiles/
    rm -rf ./CMakeCache.txt
    rm -rf ./cmake_install.cmake
    rm -rf ./CTestTestfile.cmake
fi