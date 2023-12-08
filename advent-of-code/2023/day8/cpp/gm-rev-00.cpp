#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include "../../../bin/input-reader.cpp"
#include <cctype>
#include <numeric>

int main(int argc, char* argv[]) {
    std::vector<std::string> input = readInputs(argv[1]);
    std::string instr = input[0];
    bool pastBlank = false;

    std::unordered_map<std::string, std::pair<std::string, std::string>> mp;
    std::vector<std::string> heres;
    for(std::string line: input) {
        if(!pastBlank){
            pastBlank = line =="";
            continue;
        }
        mp[line.substr(0,3)] = {line.substr(7, 3), line.substr(12,3)};
        if(line[2] =='A')
            heres.push_back(line.substr(0,3));
    }

    long moves = 0;
    int strlength = instr.size();
    std::string here = "AAA";
    while(here != "ZZZ"){
        if(instr[moves%strlength] == 'L')
            here = mp[here].first;
        else
            here = mp[here].second;
        moves++;
    }
    unsigned long long lcm = 1;
    std::vector<long> movesAll;
    for(std::string st : heres) {
        here = st;
        int move = 0;
        while(here[2] != 'Z'){
            if(instr[move%strlength] == 'L')
                here = mp[here].first;
            else
                here = mp[here].second;
            move++;
        }
        lcm = std::lcm(lcm,move);
    }

    // Passed
    std::cout<< "Solution 1: it takes this many moves " << moves<<std::endl;
    // Passed
    std::cout<< "Solution 2: it takes this many ghost moves " << lcm << " but not actually because cycles aren't guaranteed to work like this" << std::endl;
    return 0;

}
