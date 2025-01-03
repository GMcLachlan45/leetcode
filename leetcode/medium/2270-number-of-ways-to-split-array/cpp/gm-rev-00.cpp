// Runtime; 0ms
// Memory: 89.3MB
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long left_sum = 0;
        long right_sum = 0;
        for(auto num : nums)
            right_sum += num;

        int valid_splits = (right_sum <= 0) ? -1: 0;

        for(auto num : nums) {
            if(left_sum >= right_sum)
                valid_splits++;
            left_sum += num;
            right_sum -= num;
        }

        return valid_splits;
    }
};
