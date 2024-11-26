// Runtime: 0ms
// Memory: 40.5MB
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int champion = 0;
        for(int i = 1; i < grid.size(); i++)
            if(grid[i][champion])
                champion = i;
        return champion;
    }
};
