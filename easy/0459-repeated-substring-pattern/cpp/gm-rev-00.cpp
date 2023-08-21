// Runtime 59ms
// Memory 58.45MB
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 2; s.length()/i >= 1; i++) {
            if(s.length() % i)
                continue;
            std::string newstr;
            for(int j = 0; j < i; j++)
                newstr.append(s.substr(0, s.length()/i));
            if(newstr == s)
                return true;
        }
        return false;
    }
};
