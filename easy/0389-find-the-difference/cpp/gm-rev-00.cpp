// Runtime 3ms
// Memory 7.1 MB
class Solution {
public:
    char findTheDifference(string s, string t) {
        std::unordered_map<char, int> mp;
        for(char x: s)
            mp[x]++;
        for(char y: t) {
            if(mp[y] == 0)
                return y;
            mp[y]--;
        }
        return 'a';
    }
};
