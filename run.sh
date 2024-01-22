flag=$1

echo "flag: $flag"

cmake .
make 

if [ "$flag" = "test" ]; then
    ctest
else 
    ./bin/data_structure_and_algorithm_cpp
fi

echo "run.sh end $2"

if [ "$2" = "clean" ]; then
    rm -rf ./bin/
    rm -rf ./build/
    rm -rf ./Testing/
    rm -rf ./CMakeFiles/
    rm -rf ./CMakeCache.txt
    rm -rf ./cmake_install.cmake
    rm -rf ./CTestTestfile.cmake
fi