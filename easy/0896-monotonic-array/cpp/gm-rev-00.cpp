// Runtime 125ms
// Memory 96.84MB
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;
        bool dec = true;
        int i = 1;
        while(i < nums.size() && (inc || dec)){
            inc &= (nums[i-1] <= nums[i]);
            dec &= (nums[i-1] >= nums[i]);
            i++;
        }
        return inc || dec;
    }
};
