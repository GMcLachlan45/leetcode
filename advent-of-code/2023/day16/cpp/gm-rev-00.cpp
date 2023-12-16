#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include "../../../bin/input-reader.cpp"

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

int getEnergy(std::vector<std::string> inputs, std::pair<int,int> start, int direction){
    std::unordered_map<std::pair<int,int>,int, pair_hash> mp;
    std::unordered_map<std::pair<int,int>,int, pair_hash> splitterHit;

    int width = inputs[0].size();
    int height = inputs.size();
    // x,y direction, 0 north, 1 east etc
    std::queue<std::pair<std::pair<int,int>, int>> lasers;
    lasers.push({start, direction});
    while(!lasers.empty()) {
        std::pair<std::pair<int,int>, int> laser = lasers.front();
        lasers.pop();
        while(laser.first.first < width && laser.first.second < height
              && laser.first.first >= 0 && laser.first.second >= 0) {
            mp[laser.first] = 1;
            if(inputs[laser.first.second][laser.first.first] == '\\') {
                if(laser.second == 0)
                    lasers.push({{laser.first.first-1, laser.first.second},3});
                else if(laser.second == 1)
                    lasers.push({{laser.first.first, laser.first.second+1},2});
                else if(laser.second == 2)
                    lasers.push({{laser.first.first+1, laser.first.second},1});
                else if(laser.second == 3)
                    lasers.push({{laser.first.first, laser.first.second-1},0});
                break;
            } else if(inputs[laser.first.second][laser.first.first] == '/') {
                if(laser.second == 2)
                    lasers.push({{laser.first.first-1, laser.first.second},3});
                else if(laser.second == 3)
                    lasers.push({{laser.first.first, laser.first.second+1},2});
                else if(laser.second == 0)
                    lasers.push({{laser.first.first+1, laser.first.second},1});
                else if(laser.second == 1)
                    lasers.push({{laser.first.first, laser.first.second-1},0});
                break;
            } else if(inputs[laser.first.second][laser.first.first] == '|') {
                if(laser.second == 1 || laser.second == 3) {
                    if(splitterHit[laser.first])
                        break;
                    splitterHit[laser.first]++;
                    lasers.push({{laser.first.first, laser.first.second +1},2});
                    lasers.push({{laser.first.first, laser.first.second -1},0});
                    break;
                }
            } else if(inputs[laser.first.second][laser.first.first] == '-') {
                if(laser.second == 0 || laser.second == 2) {
                    if(splitterHit[laser.first])
                        break;
                    splitterHit[laser.first]++;
                    lasers.push({{laser.first.first-1, laser.first.second},3});
                    lasers.push({{laser.first.first+1, laser.first.second},1});
                    break;
                }
            }
            if(laser.second == 0)
                laser.first.second--;
            else if(laser.second == 1)
                laser.first.first++;
            else if(laser.second == 2)
                laser.first.second++;
            else if(laser.second == 3)
                laser.first.first--;
        }
    }
    return mp.size();
}

int main(int argc, char* argv[]) {
    std::vector<std::string> inputs = readInputs(argv[1]);
    int soln1 = getEnergy(inputs, {0,0}, 1);
    int max = 0;
    for(int i = 0; i < inputs.size(); i++){
        max = std::max(max, getEnergy(inputs, {0,i}, 1));
        max = std::max(max, getEnergy(inputs, {inputs[i].size()-1, i}, 3));
    }
    for(int i = 0; i < inputs[0].size(); i++){
        max = std::max(max, getEnergy(inputs, {i,0}, 2));
        max = std::max(max, getEnergy(inputs, {i, inputs.size()-1}, 0));
    }
    // Passes
    std::cout << "Solution 1: the number of enegized tiles is "<< soln1 <<std::endl;
    // Passes
    std::cout << "Solution 2: the max energizing tiles is "<< max <<std::endl;
    return 0;
}
