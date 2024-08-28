// Runtime: 290ms
// Memory: 116.1MB
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        std::queue<std::pair<int,int>> bfs;
        int subIslandCount = 0;
        for(int i = 0; i < grid2.size(); i++) {
            for(int j = 0; j < grid2[0].size(); j++) {
                if(!grid2[i][j])
                    continue;

                bfs.push({i,j});
                bool isSubIsland = true;
                while(bfs.size()) {
                    std::pair<int, int> coords = bfs.front();
                    bfs.pop();

                    if(coords.first < 0 || coords.first >= grid2.size()
                       || coords.second < 0 || coords.second >= grid2[0].size()
                       || grid2[coords.first][coords.second] == 0)
                        continue;

                    grid2[coords.first][coords.second] = 0;
                    isSubIsland &= grid1[coords.first][coords.second];

                    bfs.push({coords.first-1, coords.second});
                    bfs.push({coords.first+1, coords.second});
                    bfs.push({coords.first, coords.second-1});
                    bfs.push({coords.first, coords.second+1});
                }
                subIslandCount += isSubIsland;
            }
        }

        return subIslandCount;
    }
};
