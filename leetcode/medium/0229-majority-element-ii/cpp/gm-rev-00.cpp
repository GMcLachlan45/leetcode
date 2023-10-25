// Runtime 12ms
// Memory 16.33MB
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::unordered_map<int,int> mp;
        std::vector<int> ret;
        double lim = (double) nums.size() / 3;
        for(int x: nums) {
            mp[x]++;
            if(mp[x] > lim) {
                ret.push_back(x);
                mp[x] = -lim*3;
            }
        }
        return ret;
    }
};
