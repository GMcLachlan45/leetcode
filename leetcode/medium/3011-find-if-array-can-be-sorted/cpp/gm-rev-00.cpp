// Runtime: 0ms
// Memory: 31.33MB
class Solution {
    int countSetBits(int num) {
        int ans = 0;
        while(num) {
            ans += (num & 1);
            num >>= 1;
        }
        return ans;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int current_set_bits = 0;
        int last_max = 0;
        int current_max = 0;
        for(int num : nums) {
            int set_bits = countSetBits(num);
            if(set_bits == current_set_bits) {
                if(num < last_max)
                    return false;
                if(current_max < num)
                    current_max = num;
            } else if(num < current_max)
                return false;
            else {
                last_max = current_max;
                current_max = num;
                current_set_bits = set_bits;
            }
        }
        return true;
    }
};
