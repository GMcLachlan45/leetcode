#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "../../../bin/input-reader.cpp"

int main() {
    std::string input = readInput()+'\n';
    int numberStart = 0;
    int totalPaper = 0;
    int totalRibbon = 0;

    int dims[] = {0,0,0};
    int curr = 0;
    for(int i = 0; i < input.size(); i++) {
        if(input[i] == 'x') {
            dims[curr] = std::stoi(input.substr(numberStart, i-numberStart));
            curr++;
            numberStart = i+1;
        } else if (input[i] == '\n') {
            dims[curr] = std::stoi(input.substr(numberStart, i-numberStart));
            std::sort(std::begin(dims), std::end(dims));
            totalPaper += 2*dims[0]*dims[1]
                +2*dims[1]*dims[2]
                +2*dims[2]*dims[0]
                + dims[0]*dims[1];
            totalRibbon += 2*dims[0]+ 2*dims[1] + dims[0]*dims[1]*dims[2];
            curr = 0;
            numberStart = i+1;
        }
    }
    // Correct
    std::cout << "Solution 1: the elves should order "<< totalPaper <<" sq ft of paper." << std::endl;
    // Correct
    std::cout << "Solution 2: the elves should order "<< totalRibbon << " ft of ribbon." <<std::endl;
    return 0;
}
