// Runtime: 0ms
// Memory: 7.10MB
class Solution {
    bool isVowel(char c) {
        switch(c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                return true;
            default: return false;
        }
    }
public:
    bool halvesAreAlike(string s) {
        int vowels = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i]))
                vowels += (i < s.size()/2) ? 1 : -1;
        }
        return vowels == 0;
    }
};
