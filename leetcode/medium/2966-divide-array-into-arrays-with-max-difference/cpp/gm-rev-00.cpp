// Runtime: 119ms
// Memory: 119.62MB
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ret;
        for(int i = 0; i < nums.size(); i += 3) {
            if(nums[i+2] - nums[i] > k)
                return {};
            ret.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return ret;
    }
};
