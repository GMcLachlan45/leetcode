// Rontime 65ms
// Memory 7.18MB
class Solution {
public:
    string longestPalindrome(string s) {
        std::string longest = s.substr(0,1);
        for(int i = 0; i < s.size() - longest.size(); i++) {
            for(int j = s.size() - 1; j >=i + longest.size(); j--) {
                if(s[i] == s[j]) {
                    bool pal = true;
                    for(int k = 0;  pal && k <= (j-i)/2; k++)
                        pal = s[i+k] == s[j-k];
                    if(pal) {
                        longest = s.substr(i, j-i+1);
                        break;
                    }
                }
            }
        }
        return longest;
    }
};
