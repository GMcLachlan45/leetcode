// Runtime: 174ms
// Memory: 34.6MB
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_map<int,int> cache;
        cache[0] = -1;
        int current_cycle = 0;
        for(int i = 0; i < nums.size(); i++) {
            current_cycle += nums[i];
            current_cycle %= k;

            if(cache.find(current_cycle) == cache.end())
                cache[current_cycle] = i;
            else if (i - cache[current_cycle] > 1)
                return true;
        }
        return false;
    }
};
