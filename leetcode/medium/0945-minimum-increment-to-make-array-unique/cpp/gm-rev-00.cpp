// Runtime: 1245ms
// Memory: 110.7MB
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        std::unordered_map<int,int> mp;
        int ret = 0;
        for(int x : nums) {
            while (mp[x]) {
                ret += mp[x];
                x += mp[x]++;
             }
            mp[x]++;
        }
        return ret;
    }
};
