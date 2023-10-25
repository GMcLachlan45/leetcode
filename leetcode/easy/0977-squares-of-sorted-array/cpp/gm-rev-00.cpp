// Runtime 35ms
// Memory 26.9MB
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> ret;
        for(int x : nums)
            ret.push_back(x*x);
        std::sort(ret.begin(), ret.end());
        return ret;
    }
};
