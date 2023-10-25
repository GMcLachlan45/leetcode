// Runtime 180ms
// Memory 77.4MB

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0)
            return false;

        std::unordered_map<int, int> log;
        for(int i = 0; i < nums.size(); i++){
            if(log.count(nums[i])){
                if(i - log[nums[i]] <= k)
                    return true;
            }
            log[nums[i]] = i;
        } 

        return false;
    }
};