#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include "../../../bin/input-reader.cpp"
#include <cctype>
#include <numeric>

std::vector<long> getNums(std::string in) {
    std::vector<long> vec;
    std::string num ="";
    for(char c: in) {
        if(std::isdigit(c) || c =='-')
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
    std::vector<std::vector<long>> input;
    for(std::string st : readInputs(argv[1])) {
        input.push_back(getNums(st));
    }
    long sum = 0;
    long sum2 = 0;

    for(std::vector<long> in : input) {
        bool again = true;
        std::vector<std::vector<long>> info;
        info.push_back(in);

        bool allZero = false;
        while(!allZero) {
            allZero = true;
            info.push_back({});
            for(long i = 1; i < info[info.size()-2].size(); i++) {
                info[info.size()-1].push_back(info[info.size()-2][i]-info[info.size()-2][i-1]);
                allZero = allZero && info[info.size()-1][i-1] == 0;
            }
        }

        info[info.size()-1].push_back(0);
        for(long b = info.size()-1; b > 0; b--)
            info[b-1].push_back(info[b][info[b].size()-1] + info[b-1][info[b-1].size()-1]);
        info[info.size()-1].push_back(0);
        sum+= info[0][info[0].size()-1];
        for(long b = info.size()-1; b > 0; b--)
            info[b-1].push_back(-info[b][info[b].size()-1] + info[b-1][0]);
        sum2+= info[0][info[0].size()-1];

    }

    // Passed
    std::cout<< "Solution 1: the sum of the extrapolated values going forward is " << sum <<std::endl;
    // Passed
    std::cout<< "Solution 2: the sum of the extrapolated values going backward is " << sum2 <<std::endl;
    return 0;

}
