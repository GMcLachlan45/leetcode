#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../../bin/input-reader.cpp"
#include <cctype>
#include <utility>

std::vector<long> getNums(std::string in) {
    std::vector<long> vec;
    std::string num ="";
    for(char c: in) {
        if(std::isdigit(c))
            num += c;
        else{
            if(num!="")
                vec.push_back(std::stol(num));
            num = "";
        }
    }
    vec.push_back(std::stol(num));
    return vec;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> input = readInputs(argv[1]);

    std::vector<long> seeds = getNums(input[0]);


    std::vector<std::vector<std::vector<long>>> maps;
    std::vector<std::vector<long>> tuples;
    for(int line = 1; line < input.size(); line++) {
        if(input[line] == "" || !std::isdigit(input[line][0])) {
            if(!tuples.empty()){
                maps.push_back(tuples);
                tuples.clear();
            }
            continue;
        }
        else
            tuples.push_back(getNums(input[line]));
    }
    maps.push_back(tuples);


    std::cout<<std::endl;
    for(int i = 0; i < maps.size(); i++) {
        std::sort(maps[i].begin(), maps[i].end(), [](auto &left, auto &right) {
            return left[1] < right[1];
        });
        std::cout << i<< ":"<<std::endl;
        for(int j = 0; j <maps[i].size(); j++) {
            std::cout<<maps[i][j][0]<<" "<<maps[i][j][1]<<" "<<maps[i][j][2]<<" "<<std::endl;
        }
    }

    std::cout<<std::endl;
    for(int level = 0; level < maps.size(); level++) {
        for(int seed = 0; seed < seeds.size(); seed++) {
            int j = 0;

            while (j<maps[level].size() &&( seeds[seed] < maps[level][j][1] || seeds[seed] >= maps[level][j][1] + maps[level][j][2]))
                j++;
            if(j < maps[level].size())
                seeds[seed] =  maps[level][j][0] + seeds[seed]- maps[level][j][1];

        }
    }
    std::sort(seeds.begin(), seeds.end());
    // Complete
    std::cout<< "Solution 1: the closest location is: " << seeds[0] <<std::endl;
    std::cout<< "Solution 1: the closest location for seed ranges is: " << seeds[0] <<std::endl;

    return 0;

}
