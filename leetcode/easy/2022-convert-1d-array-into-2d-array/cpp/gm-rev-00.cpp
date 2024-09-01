// Runtime: 88ms
// Memory: 88.1MB
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(n*m !=original.size())
            return {};
        std::vector<std::vector<int>> ans(m, std::vector<int>(n));
        for(int i = 0; i< original.size(); i+=n) {
            std::copy(original.begin() + i, original.begin() + i+n, ans[i/n].begin());
        }

        return ans;
    }
};
