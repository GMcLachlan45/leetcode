#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

std::vector<std::string> readInput(std::string filepath) {
    std::ifstream infile(filepath.c_str());
    std::string line;
    std::vector<std::string> ret;
    while(infile >> line)
        ret.push_back(line);
    return ret;
}

int tilesGuarded(int x, int y, std::vector<std::string> map1){
    int dir = 0;
    int ans1 = 0;
    while(x >= 0 && x < map1[0].size() && y >= 0 && y < map1.size()) {
        if(map1[y][x] == '.') {
            ans1++;
            map1[y][x] = (char) 0;
        } else if(map1[y][x] == '#') {
            if(dir == 0) {
                y++;
            } else if(dir == 1)
                x--;
            else if(dir == 2)
                y--;
            else
                x++;
            dir = (dir + 1)%4;
            map1[y][x] |= (1 << dir);
        }

        map1[y][x] |= (1 << dir);
        x = x + (dir == 1) - (dir == 3);
        y = y + (dir == 2) - (dir == 0);
    }
    return ans1;
}

bool makesLoop(int x, int y, std::vector<std::string> map) {
    std::vector<std::vector<std::vector<bool>>> visited(4, std::vector<std::vector<bool>>(map[0].size(), std::vector<bool>(map.size(), false)));

    int dir = 0;
    while(x >= 0 && x < map[0].size() && y >= 0 && y < map.size()) {
        if(map[y][x] == '#') {
            if(dir == 0) {
                y++;
            } else if(dir == 1)
                x--;
            else if(dir == 2)
                y--;
            else
                x++;
            dir = (dir + 1)%4;
        }
        if(visited[dir][x][y])
            return true;
        visited[dir][x][y] = true;
        x = x + (dir == 1) - (dir == 3);
        y = y + (dir == 2) - (dir == 0);
    }

    return false;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> input = readInput(argv[1]);

    int x = -1; int y = -1;
    for(int i = 0; x < 0 && i < input.size(); i++)
        for(int j = 0; j < input[i].size(); j++)
            if(input[i][j] == '^') {
                input[i][j] = '.';
                x = j;
                y = i;
                break;
            }

    // Passed
    std::cout << "Solution 1: The guard travels on " <<tilesGuarded(x,y,input)<<" unique tiles"<<std::endl;

    int ans2 = 0;
    for(int i = 0; i < input.size(); i++)
        for(int j = 0; j < input[i].size(); j++)
            if(i != y || j != x) {
                char temp = input[i][j];
                input[i][j] = '#';
                if(makesLoop(x,y,input))
                    ans2++;

                input[i][j] = temp;
            }

// Passed
    std::cout << "Solution 2: There are "<<ans2<<" ways to block the guard."<<std::endl;

}
