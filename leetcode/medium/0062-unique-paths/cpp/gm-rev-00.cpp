// Runtime: 2ms
// Memory: 7.1MB
class Solution {
public:
    int uniquePaths(int m, int n) {
        int total = 0;
        std::vector<std::vector<int>> ways(m, {1});
        for(int i = 1; i < n; i++)
            ways[0].push_back(1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++)
                ways[i].push_back(ways[i][j-1] + ways[i-1][j]);
        }
        return ways[m-1][n-1];
    }
};
