#include <string>
#include <iostream>
#include <vector>
#include "../../../bin/input-reader.cpp"

std::vector<std::string> parseLine(std::string in) {
    std::vector<std::string> ret;

    int numBegin = -1;
    for(int i = 0; i < in.size(); i++){
        if(in[i] == ',') {
            if(numBegin != -1)
                ret.push_back(in.substr(numBegin, i-numBegin));
                numBegin = -1;
            continue;
        }else {
            if(numBegin == -1)
                numBegin = i;
        }
    }
    ret.push_back(in.substr(numBegin, in.size()-numBegin));
    return ret;
}

int HASH(std::string in){
        int thisHash = 0;
        for(char c : in) {
            thisHash= (thisHash+(int) c)*17;
            thisHash %=256;
        }
        return thisHash;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> inputs = parseLine(readInput(argv[1]));

    int ans = 0;
    std::vector<int> hashes;
    std::vector<std::pair<std::string,int>> lenses;

    for(std::string s: inputs){
        int thisHash = HASH(s);
        if(s[s.size()-1] == '-'){
            lenses.push_back({s.substr(0,s.size()-1), -1});
            hashes.push_back(HASH(s.substr(0,s.size()-1)));
        }else{
            lenses.push_back({s.substr(0,s.size()-2), s[s.size()-1] - '0'});
            hashes.push_back(HASH(s.substr(0,s.size()-2)));
        }
        ans += thisHash;
    }

    std::vector<std::vector<std::pair<std::string,int>>> goods(256);
    for(int i = 0; i < lenses.size(); i++) {
        bool modded = false;
        for(int j = 0; j < goods[hashes[i]].size(); j++) {
            if(goods[hashes[i]][j].first == lenses[i].first) {
                if(lenses[i].second == -1) {
                    goods[hashes[i]].erase(goods[hashes[i]].begin() +j);
                } else
                    goods[hashes[i]][j].second =lenses[i].second;
                modded = true;
                break;
            }
        }
        if(!modded &&lenses[i].second != -1) {
            goods[hashes[i]].push_back(lenses[i]);
        }
    }


    int sum = 0;
    for(int i = 0; i < 256; i++) {
        for(int j = 0; j < goods[i].size(); j++) {
            sum += (i+1)*(j+1)*goods[i][j].second;
        }
    }

    std::cout <<"Solution 1: the sum of the hashes is "<< ans<<std::endl;
    std::cout <<"Solution 2: the total magnifying power is "<< sum<<std::endl;
    return 0;
}
