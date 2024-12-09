#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

std::vector<std::string> readInput(std::string filepath) {
    std::ifstream infile(filepath.c_str());
    std::string line;
    std::vector<std::string> ret;
    while(std::getline(infile, line))
        ret.push_back(line);
    return ret;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> input = readInput(argv[1]);

    int ans1 = 0;
    std::vector<std::vector<std::pair<int,int>>> antennas(128, std::vector<std::pair<int,int>>());
    std::vector<std::pair<int,int>> candidates;


    for(int x = 0; x < input[0].size(); x++) {
        for(int y = 0; y < input.size(); y++) {
            if(input[y][x] == '.')
                continue;
            for(std::pair<int,int> antenna : antennas[input[y][x]]) {
                int delta_x = x - antenna.first;
                int delta_y = y - antenna.second;
                candidates.push_back({antenna.first - delta_x, antenna.second - delta_y});
                candidates.push_back({x + delta_x, y + delta_y});
            }
            antennas[input[y][x]].push_back({x,y});
        }
    }

    std::vector<std::vector<bool>> antinode(input.size(), std::vector<bool>(input[0].size(), false));
    for(std::pair<int,int> candidate : candidates) {
        if(candidate.first >= 0 && candidate.first < input[0].size()
           && candidate.second >= 0 && candidate.second < input.size()
            && !antinode[candidate.second][candidate.first]){
            ans1++;
            antinode[candidate.second][candidate.first] = true;
        }
    }

// Passed
    std::cout << "Solution 1: There are " <<ans1<<" antinodes."<<std::endl;

    int ans2 = 0;
    antennas = std::vector<std::vector<std::pair<int,int>>>(128, std::vector<std::pair<int,int>>());
    candidates = {};

    for(int x = 0; x < input[0].size(); x++) {
        for(int y = 0; y < input.size(); y++) {
            if(input[y][x] == '.')
                continue;
            for(std::pair<int,int> antenna : antennas[input[y][x]]) {
                int delta_x = x - antenna.first;
                int delta_y = y - antenna.second;
                for(int i = 0; antenna.first - i*delta_x >= 0; i++)
                    candidates.push_back({antenna.first - i*delta_x, antenna.second - i*delta_y});
                for(int i = 0; antenna.first + i*delta_x < input[0].size(); i++)
                    candidates.push_back({x + i*delta_x, y + i*delta_y});

            }
            antennas[input[y][x]].push_back({x,y});
        }
    }

     antinode = std::vector<std::vector<bool>>(input.size(), std::vector<bool>(input[0].size(), false));
    for(std::pair<int,int> candidate : candidates) {
        if(candidate.first >= 0 && candidate.first < input[0].size()
           && candidate.second >= 0 && candidate.second < input.size()
            && !antinode[candidate.second][candidate.first]){
            ans2++;
            antinode[candidate.second][candidate.first] = true;
        }
    }

// Passed
    std::cout << "Solution 2: There are actually "<<ans2<<" antinodes."<<std::endl;

}
