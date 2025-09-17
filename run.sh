flag=$1
test_target=$2
for last; do true; done

cmake -D CMAKE_BUILD_TYPE=Debug .
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