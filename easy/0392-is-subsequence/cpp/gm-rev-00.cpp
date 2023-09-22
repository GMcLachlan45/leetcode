// Runtime 0ms
// Memory 6.98MB
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(int i = 0; i < t.size() && idx < s.size(); i++) {
            if(t[i] == s[idx])
                idx++;
        }
        return idx == s.size();
    }
};
