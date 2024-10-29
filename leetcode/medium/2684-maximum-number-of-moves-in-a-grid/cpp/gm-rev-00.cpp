// Runtime: 11ms
// Memory: 70.68MB
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        std::queue<std::pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++)
            q.push({i, 0});
        std::vector<bool> queued(grid.size(), false);
        int current_column = 0;
        while(!q.empty() && q.front().second < grid[0].size()-1) {
            if(q.front().second > current_column) {
                current_column++;
                queued = std::vector<bool>(grid.size(), false);
            }
            if(q.front().first > 0 && !queued[q.front().first - 1]
               && grid[q.front().first][q.front().second] < grid[q.front().first - 1][q.front().second + 1]) {
                q.push({q.front().first - 1, q.front().second + 1});
            }
            if(!queued[q.front().first]
               && grid[q.front().first][q.front().second] < grid[q.front().first][q.front().second + 1]) {
                q.push({q.front().first, q.front().second + 1});
                queued[q.front().first] = true;
            }
            if(q.front().first < grid.size()-1 && grid[q.front().first][q.front().second] < grid[q.front().first + 1][q.front().second + 1]) {
                q.push({q.front().first + 1, q.front().second + 1});
                queued[q.front().first + 1] = true;
            }
            q.pop();
        }
        if(!q.empty())
            return grid[0].size()-1;
        return current_column;
    }
};
