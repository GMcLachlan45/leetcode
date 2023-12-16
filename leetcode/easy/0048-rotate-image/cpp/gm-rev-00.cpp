// Runtime: 0ms
// Memory: 7.44MB
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int y = 0; y < n/2; y++) {
            for(int x = 0; x < n/2 + (n%2); x++) {
                int temp = matrix[y][x];
                matrix[y][x] = matrix[n-1-x][y];
                matrix[n-1-x][y] = matrix[n-1-y][n-1-x];
                matrix[n-1-y][n-1-x] = matrix[x][n-1-y];
                matrix[x][n-1-y] = temp;
            }
        }
    }
};
