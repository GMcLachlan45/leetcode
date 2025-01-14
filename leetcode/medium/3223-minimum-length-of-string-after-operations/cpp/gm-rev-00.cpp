// Runtime: 27ms
// Memory: 32MB
class Solution {
public:
    int minimumLength(string s) {
        bool in_string[26];
        bool odd[26];
        int ans = 0;
        for(char c : s) {
            if(in_string[c-'a']) {
                if(odd[c - 'a'])
                    ans++;
                else
                    ans--;
            } else {
                in_string[c-'a'] = true;
                ans++;
            }
            odd[c - 'a'] ^= true;
        }
        return ans;
    }
};
