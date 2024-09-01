// Runtime: 88ms
// Memory: 88.1MB
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(n*m !=original.size())
            return {};
        std::vector<std::vector<int>> ans(m, std::vector<int>(n));
        for(int i = 0; i < original.size(); i++)
            ans[i/n][i%n] = original[i];
        return ans;
    }
};
