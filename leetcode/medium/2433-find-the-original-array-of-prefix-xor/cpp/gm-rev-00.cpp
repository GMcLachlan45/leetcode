// Runtime: 100ms
// Memory: 76.5MB
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        std::vector<int> ret(pref.size());
        ret[0] = pref[0];
        for(int i = 1; i < pref.size(); i++)
           ret[i] = pref[i] ^ pref[i-1];
        return ret;
    }
};
