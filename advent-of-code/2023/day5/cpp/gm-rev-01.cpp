#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "../../../bin/input-reader.cpp"
#include <cctype>
#include <utility>
#include <limits>

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

class range {
public:
    long start;
    long end;
    range(long start, long length) {
        this->start = start;
        this->end = start + length-1;
    }
    void translate(long delta){
        start+= delta;
        end+= delta;
    }
    std::pair<range,range> partition (long pivot) {
        return {range(this->start, pivot-this->start+1),  range(pivot, end-pivot+1)};
    }
    void print(){
        std::cout <<"["<<this->start<<","<<this->end<<"]"<<" ";
    }
};

int main(int argc, char* argv[]) {
    std::vector<std::string> input = readInputs(argv[1]);
    input.push_back("");
    std::vector<long> seeds = getNums(input[0]);
    std::vector<range> seedRanges;
    for(int i = 0; i < seeds.size(); i+=2) {
        seedRanges.push_back(range(seeds[i], seeds[i+1]));
    }

    std::vector<std::vector<std::pair<long,long>>> maps;
    // pairs with source, and the offset past that
    std::vector<std::pair<long,long>> tuples;
    std::unordered_set<long> beforeRanges;
    std::unordered_set<long> afterRanges;


    long MAX = std::numeric_limits<long>::max();
    for(int line = 1; line < input.size(); line++) {
        afterRanges.insert(0);
        if(input[line] == "" || !std::isdigit(input[line][0])) {
            if(!tuples.empty()){
                for(long x : afterRanges)
                    tuples.push_back({x,0});
                tuples.push_back({MAX, 0});
                maps.push_back(tuples);
                tuples.clear();
                beforeRanges.clear();
                afterRanges.clear();
            }
            continue;
        }
        else{
            std::vector<long> nums = getNums(input[line]);
            tuples.push_back({nums[1], nums[0]-nums[1]});
            beforeRanges.insert(nums[1]);
            // If we added this to the set of after ranges, remove that,
            if(afterRanges.count(nums[1]))
                afterRanges.erase(nums[1]);
            if(!beforeRanges.count(nums[1]+ nums[2]))
                afterRanges.insert(nums[1]+nums[2]);
        }
    }

    for(int i = 0; i < maps.size(); i++) {
        std::sort(maps[i].begin(), maps[i].end());
    }

    for(int i = 0; i < maps.size(); i++) {
        std::vector<range> nextRanges;
        for(int seeds = 0; seeds <seedRanges.size(); seeds++) {
            int j = 0;
            while(j <maps[i].size()-1 && maps[i][j+1].first <= seedRanges[seeds].start)
                j++;
            if(j == maps[i].size()-2) {
                nextRanges.push_back(seedRanges[seeds]);
            } else {
                if(maps[i][j+1].first<seedRanges[seeds].end) {
                    auto pair = seedRanges[seeds].partition(maps[i][j+1].first);
                    pair.first.translate(maps[i][j].second);
                    nextRanges.push_back(pair.first);
                    seedRanges.push_back(pair.second);
                } else {
                    seedRanges[seeds].translate(maps[i][j].second);
                    nextRanges.push_back(seedRanges[seeds]);
                }
            }
        }
        seedRanges = nextRanges;
    }
    std::sort(seedRanges.begin(), seedRanges.end(), [] (auto l, auto r) {
        return l.start<r.start;
    });
    // Passes
    std::cout<< "Solution 2: the closest location for seed ranges is: " << seedRanges[0].start <<std::endl;

    return 0;

}
