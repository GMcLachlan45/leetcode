// Runtime: 0ms
// Memory: 31.28MB
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int current_set_bits = 0;
        int last_max = 0;
        int current_max = 0;
        for(unsigned int num : nums) {
            int set_bits = std::popcount(num);
            if(set_bits != current_set_bits) {
                last_max = current_max;
                current_max = num;
                current_set_bits = set_bits;
            }
            if(num < last_max)
                return false;
            if(num > current_max)
                current_max = num;
        }
        return true;
    }
};
