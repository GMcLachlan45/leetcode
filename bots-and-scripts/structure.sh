#!/bin/sh
mkdir cpp
cd cpp
mkdir bin
touch gm-rev-00.cpp
echo "#include <string>
#include <iostream>
#include <vector>
#include \"../../../bin/input-reader.cpp\"

int main(int argc, char* argv[]) {
    std::vector<std::string> inputs = readInputs(argv[1]);
    int ans = 0;
    std::cout << ans<<std::endl;
    return 0;
}" > gm-rev-00.cpp
