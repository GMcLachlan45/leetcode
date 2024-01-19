// Runtime: 14ms
// Memory: 12.65MB
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int m = matrix.size()-2; m >= 0; m--) {
            for(int n = 0; n < matrix[m].size(); n++) {
                int min = matrix[m][n] + matrix[m+1][n];
                if(n > 0)
                    min = std::min(min,  matrix[m][n] + matrix[m+1][n-1]);
                if(n < matrix[m].size()-1)
                    min = std::min(min,  matrix[m][n] + matrix[m+1][n+1]);
                matrix[m][n] = min;
            }
        }
        int solution = matrix[0][0];
        for(int x : matrix[0])
            solution = std::min(solution, x);
        return solution;
    }
};
