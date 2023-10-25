// Runtime 12ms
// Memory 14MB

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), target));
        int l = std::distance(nums.begin(), std::upper_bound(nums.begin(), nums.end(), target)) -1;
        if(f>= nums.size() || nums[f] != target)
            return {-1,-1};
        return {f, l};
    }
};
