// Runtime 4ms
// Memory 6.72MB
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<vector<int>> pascalTriangle;
        for(int i = 0; i < numRows; i++) {
            std::vector<int> row;
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i)
                    row.push_back(1);
                else
                    row.push_back(pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j]);
            }
            pascalTriangle.push_back(row);
        }
        return pascalTriangle;
    }
};
