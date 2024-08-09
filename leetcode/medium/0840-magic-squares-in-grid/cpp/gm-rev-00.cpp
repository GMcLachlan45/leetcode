// Runtime: 0ms
// Memory: 10.4MB
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size() < 3 || grid[0].size() < 3)
            return 0;
        int ans = 0;
        for(int i = 0; i < grid.size()-2; i++)
            for(int j = 0; j < grid[i].size()-2; j++)
                if(grid[i][j] * grid[i][j + 1] * grid[i][j + 2]
                   * grid[i + 1][j] * grid[i + 1][j + 1] * grid[i + 1][j + 2]
                   * grid[i + 2][j] * grid[i + 2][j + 1] * grid[i + 2][j + 2] == 362880
                   && grid[i][j] + grid[i][j + 1] + grid[i][j + 2] == 15
                   && grid[i][j] + grid[i + 1][j] + grid[i + 2][j] == 15
                   && grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] == 15
                   && grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] == 15                               && grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] == 15
                   && grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] == 15
                   && grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15
                   && grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] == 15)
                    ans++;
        return ans;
    }
};
