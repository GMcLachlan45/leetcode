// Runtime 83ms
// Memory 55.05MB
class Solution {
    int rev(int num) {
        int ret = 0;
        while(num > 0) {
            ret = 10*ret + num%10;
            num/=10;
        }
        return ret;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int MOD = 1000000007;
        long long count = 0;
        for(int i = 0; i < nums.size(); i++)
            nums[i] -= rev(nums[i]);
        std::sort(nums.begin(), nums.end());
        int num = 1000000001;
        int inARow = 1;
        for(int x : nums) {
            if(num == x){
                inARow++;
                count += inARow-1;
            } else {
                num = x;
                inARow = 1;
            }
        }
        return count % MOD;
    }
};
