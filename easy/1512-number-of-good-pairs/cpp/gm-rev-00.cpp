// Runtime 3ms
// Memory 7.56MB
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        std::unordered_map<int,int> mp;
        int ret = 0;
        for(int x: nums) {
            ret += mp[x];
            mp[x]++;
        }
        return ret;
    }
};
