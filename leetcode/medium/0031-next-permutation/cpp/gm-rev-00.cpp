// Runtime: 0ms
// Memory: 14.5MB
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find last place with an increase
        int l = -1;
        for(int i = nums.size()-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]){
                l = i;
                break;
            }
        }

        // if one exists, find the least upper bound of nums[l]
        int r = l;
        if(l !=-1) {
            for(int i = l+1; i < nums.size() && nums[l] < nums[i]; i++) {
                r = i;
            }
            // swap
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
        }

        // Finally, swap all the other numbers after the swap that took place
        l++;
        r = nums.size()-1;
        while(l < r) {
            int temp = nums[l];
            nums[l++] = nums[r];
            nums[r--] = temp;
        }
    }
};
