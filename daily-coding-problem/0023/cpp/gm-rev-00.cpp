#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_set>

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

int minSteps(std::vector<std::vector<bool>> maze, std::vector<int> start, std::vector<int> end) {
    std::pair<int,int> endPair = {end[0], end[1]};
    // hold the number of steps to the coordinate as {steps, {y,x}}
    std::queue<std::pair<int,std::pair<int,int>>> bfs;
    std::unordered_set<std::pair<int,int>, pair_hash> visited;
    bfs.push({0, {start[0], start[1]}});
    while(!bfs.empty()) {
        // if visited, or outside of grid or in a wall, just want to pop.
        if(visited.count(bfs.front().second)
           ||bfs.front().second.first < 0 || bfs.front().second.second < 0
           || bfs.front().second.first >= maze.size() || bfs.front().second.second >= maze[bfs.front().second.first].size()
           || maze[bfs.front().second.first][bfs.front().second.second]);
        else if(bfs.front().second == endPair)
            return bfs.front().first;
        else {
            bfs.push({bfs.front().first+1, {bfs.front().second.first + 1, bfs.front().second.second}});
            bfs.push({bfs.front().first+1, {bfs.front().second.first - 1, bfs.front().second.second}});
            bfs.push({bfs.front().first+1, {bfs.front().second.first, bfs.front().second.second + 1}});
            bfs.push({bfs.front().first+1, {bfs.front().second.first, bfs.front().second.second - 1}});
        }
        visited.insert(bfs.front().second);
        bfs.pop();
    }
    return -1;
}

int main() {
    std::vector<std::vector<bool>> maze = {{0,0,0,0},
                                           {1,1,0,1},
                                           {0,0,0,0},
                                           {0,0,0,0}};
    std::vector<int> start = {3,0};
    std::vector<int> end = {0,0};

    int ans = minSteps(maze, start, end);
    if(ans == -1)
        std::cout << "There is no path from " << start[0] << "," << start[1] << " to " << end[0] << "," << end[1]<<std::endl;
    else
        std::cout << "The minimum number of steps to go from "<< start[0] << "," << start[1] << " to " << end[0] << "," << end[1] <<" is " << ans << std::endl;

    maze = {{0,0,0,0},
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0}};
    start = {3,0};
    end = {0,0};

    ans = minSteps(maze, start, end);
    if(ans == -1)
        std::cout << "There is no path from " << start[0] << "," << start[1] << " to " << end[0] << "," << end[1]<<std::endl;
    else
        std::cout << "The minimum number of steps to go from "<< start[0] << "," << start[1] << " to " << end[0] << "," << end[1] <<" is " << ans << std::endl;


}
