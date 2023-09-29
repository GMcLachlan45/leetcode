// Runtime 125ms
// Memory 96.84MB
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return std::is_sorted(nums.begin(), nums.end()) || std::is_sorted(nums.begin(), nums.end(), std::greater<>());
    }
};
