// Runtime: 145ms
// Memory: 82.2MB
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0;
        int r = 0;
        std::multiset<int> elems;
        elems.insert(nums[r]);
        r++;
        int maxLength = 1;
        while(r < nums.size()) {
            while(std::abs((*elems.begin()) - (*elems.rbegin())) <= limit && r < nums.size()) {
                elems.insert(nums[r]);
                r++;
            }
            maxLength = std::max(maxLength, (std::abs((*elems.begin()) - (*elems.rbegin())) <= limit) ? r-l :r-1-l);
            while(std::abs((*elems.begin()) - (*elems.rbegin())) > limit) {
                elems.extract(nums[l]);
                l++;
            }
        }
        return maxLength;
    }
};
