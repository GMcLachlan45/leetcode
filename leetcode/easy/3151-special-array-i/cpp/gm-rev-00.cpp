// Runtime: 0ms
// Memory: 27.7MB
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            if(((nums[i-1] ^ nums[i]) & 1) == 0)
                return false;
        return true;
    }
};
