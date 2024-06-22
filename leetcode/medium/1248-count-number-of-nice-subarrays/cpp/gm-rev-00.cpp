// Runtime: 90ms
// Memory: 69.9MB
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int niceCount = 0;

        int oddCount = 0;
        int l = 0;
        int r = 0;
        while(r < nums.size()) {
            while(r < nums.size() && oddCount < k) {
                if(nums[r] % 2 == 1)
                    oddCount++;
                r++;
            }
            if(oddCount < k)
                break;
            int preceedingZeros = 0;
            while(l < r && nums[l]%2 == 0) {
                preceedingZeros++;
                l++;
            }
            int succeedingZeros = 0;
            while(r < nums.size() && nums[r]%2 == 0) {
                succeedingZeros++;
                r++;
            }
            niceCount += (preceedingZeros + 1) * (succeedingZeros + 1);

            l++;
            oddCount--;
        }
        return niceCount;

    }
};
