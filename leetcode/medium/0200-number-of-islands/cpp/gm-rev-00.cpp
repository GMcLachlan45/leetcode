// Runtime 37ms
// Memory 12.3

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int x, int y){
        grid[x][y] = '0';
        if(x + 1 < grid.size() && grid[x + 1][y] == '1')
            dfs(grid, x + 1, y);
        if(y + 1 < grid[0].size() && grid[x][y + 1] == '1')
            dfs(grid, x, y + 1);
        if(x - 1 >= 0 && grid[x - 1][y] == '1')
            dfs(grid, x - 1, y);
        if(y - 1 >= 0 && grid[x][y - 1] == '1')
            dfs(grid, x, y - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int number_of_islands = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    number_of_islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return number_of_islands;
    }
};
