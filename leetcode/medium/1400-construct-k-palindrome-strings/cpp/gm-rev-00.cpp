// Runtime: 0ms
// Memory: 14.9MB
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size())
            return false;
        int count[26];
        for(char c : s)
            count[c-'a']++;
        int odds = 0;
        for(int i = 0; i < 26; i++)
            odds += 1 & count[i];
        return odds <= k;
    }
};
