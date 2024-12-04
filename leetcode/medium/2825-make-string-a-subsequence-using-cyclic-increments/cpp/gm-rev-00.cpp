// Runtime: 11ms
// Memory: 16.9MB
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str1.size() < str2.size())
            return false;
        for(int i = 0; i < str2.size(); i++)
            str2[i] -='a';
        int s_ptr = 0;
        for(char c : str1) {
            c -= 'a';
            if(c == str2[s_ptr] || ((c + 1)%26) == str2[s_ptr])
                s_ptr++;
        }
        return s_ptr >= str2.size();
    }
};
