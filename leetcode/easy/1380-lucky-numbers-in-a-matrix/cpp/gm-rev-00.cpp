// Runtime: 22ms
// Memory 11.4MB
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> col_max(matrix[0].size(), 0);
        vector<int> row_min(matrix.size(), 100001);

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] < row_min[i])
                    row_min[i] = matrix[i][j];
                if(matrix[i][j] > col_max[j])
                    col_max[j] = matrix[i][j];
            }
        }

        std::vector<int> lucky_numbers;
        for(int x : col_max)
            if(std::find(row_min.begin(), row_min.end(), x) != row_min.end())
                lucky_numbers.push_back(x);
        
        return lucky_numbers;
    }
};
