// Runtime: 30ms
// Memory: 32.5MB

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        std::vector<int> num_count(k);
        num_count[0]++;
        int current_cycle = 0;
        int ret = 0;
        for(int x : nums) {
            current_cycle += x;
            current_cycle %= k;
            if(current_cycle < 0)
                current_cycle += k;
            ret += num_count[current_cycle];
            num_count[current_cycle]++;
        }
        return ret;
    }
};
