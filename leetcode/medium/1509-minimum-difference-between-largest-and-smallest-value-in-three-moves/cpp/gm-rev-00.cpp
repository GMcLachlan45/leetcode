// Runtime: 63ms
// Memory: 37.6 MB
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() < 5)
            return 0;
        if(nums.size() > 6) {
            int small[] = {1000000001,1000000001,1000000001,1000000001};
            int big[] = {-1000000001,-1000000001,-1000000001,-1000000001};
            for(int x : nums) {
                for(int i = 0; i < 4; i++) {
                    if(x < small[i]) {
                        for(int j = 3; j > i; j--)
                            small[j] = small[j-1];
                        small[i] = x;
                        break;
                    }
                }
                for(int i = 0; i < 4; i++) {
                    if(x > big[i]) {
                        for(int j = 3; j > i; j--)
                            big[j] = big[j-1];
                        big[i] = x;
                        break;
                    }
                }
            }
            return std::min(
                std::min(big[3]-small[0], big[2]-small[1]),
                std::min(big[1]-small[2], big[0]-small[3])
                );
        }
        std::sort(nums.begin(), nums.end());
        int offset = (nums.size() == 5) ? 1 : 2;
        int ans = 2000000000;
        for(int i = 0; i < nums.size() - offset; i++)
            ans = std::min(ans, nums[i+offset]-nums[i]);
        return ans;
    }
};
