// Runtime: 10ms
// Memory: 11.15MB
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int x = (matrix[0].size());
        int y = matrix.size();
        std::vector<std::vector<int>> matrixT(x, std::vector<int>(y));
        for(int i = 0; i < y; i++) {
            for(int j = 0; j < x; j++)
                matrixT[j][i] = matrix[i][j];
       }
       return matrixT;
    }
};
