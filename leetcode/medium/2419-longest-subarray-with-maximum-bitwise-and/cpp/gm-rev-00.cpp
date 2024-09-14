// Runtime: 97ms
// Memory: 84.9MB
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        nums.push_back(-1);
        int ans = 0;
        int maxInt = 0;

        int ptr = 0;
        while(ptr < nums.size()-1) {
            int numStart = ptr;
            while(nums[ptr] == nums[numStart])
                ptr++;

            if(nums[numStart] >= maxInt) {
                if(nums[numStart] > maxInt || ptr-numStart > ans)
                    ans = ptr-numStart;
                maxInt = nums[numStart];
            }
        }
        return ans;
    }
};
