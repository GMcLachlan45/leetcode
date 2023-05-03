// Runtime 9ms
// Memory 10.5MB
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        int sum = 0;
        for(int x : nums)
            sum += x;
        
        int subsequence_sum = 0;
        int end_ptr = 0;
        while(sum - subsequence_sum >= subsequence_sum)
            subsequence_sum += nums[end_ptr++];

        return std::vector<int>(nums.begin(), nums.begin() + end_ptr);
    }
};
