// Runtime 4ms
// Memory 16.49MB
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            if(nums[l]%2 == 1) {
                while(l < r && nums[r]%2 == 1)
                    r--;
                int temp = nums[r];
                nums[r] = nums[l];
                nums[l] = temp;
            }
            l++;
        }
        return nums;
    }
};
