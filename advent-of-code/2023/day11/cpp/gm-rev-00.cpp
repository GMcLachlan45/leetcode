#include <string>
#include <iostream>
#include <vector>
#include "../../../bin/input-reader.cpp"

int main(int argc, char* argv[]) {
    std::vector<std::string> input = readInputs(argv[1]);

    std::vector<bool> rowBlanks(input.size(), true);
    std::vector<bool> colBlanks(input[1].size(), true);
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[0].size(); j++) {
            if(input[i][j] == '#'){
                rowBlanks[i] = false;
                colBlanks[j] = false;
            }
        }
    }

    std::vector<std::pair<long,long>> galaxiesSmall;
    std::vector<std::pair<long long,long long>> galaxiesBig;
    int extraYSpace = 0;
    for(int i = 0; i < input.size(); i++) {
        int extraXSpace = 0;
        if(rowBlanks[i]){
            extraYSpace++;
            continue;
        }
        for(int j = 0; j < input[0].size(); j++) {
            if(colBlanks[j]){
                extraXSpace++;
                continue;
            }
            if(input[i][j] == '#'){
                galaxiesSmall.push_back({j+extraXSpace, i + extraYSpace});
                galaxiesBig.push_back({j+extraXSpace*999999, i + extraYSpace*999999});
            }
        }
    }

    long long smallSum = 0;
    long long bigSum = 0;
    for(int i = 0; i < galaxiesBig.size(); i++) {
        for(int j = i+1; j < galaxiesBig.size(); j++) {
            smallSum += std::abs(galaxiesSmall[i].first - galaxiesSmall[j].first)  +std::abs(galaxiesSmall[i].second - galaxiesSmall[j].second);
            bigSum += std::abs(galaxiesBig[i].first - galaxiesBig[j].first)  +std::abs(galaxiesBig[i].second - galaxiesBig[j].second);

        }
    }
    // Passes
    std::cout<< "Solution 1: The distance between galaxies is " << smallSum << std::endl;
    // Passes
    std::cout<< "Solution 2: The huge distance between galaxies is " << bigSum << std::endl;
    return 0;

}
