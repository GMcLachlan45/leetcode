// Runtime 175ms
// Memory 109.7MB
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < (short)k; i++){
            sum += nums[i];
        }
        int max = sum;

        for(int i = k; i < nums.size(); i++){
            sum += nums[i] - nums[i-k];
            if(sum > max)
                max = sum;
        }
        return max * 1.0 / k;
    }
};
