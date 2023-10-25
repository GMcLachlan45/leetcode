// Runtime 150ms
// Memory 20.1MB
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        std::sort(s.begin(), s.end(), std::greater<char>());

        int next_char = 0;
        int char_count = 1;
        for(int i = 1; i < s.size(); i++) {
            if(char_count >= repeatLimit && s[i-1] == s[i]) {
                next_char = std::max(next_char, i);
                while(next_char < s.size() && s[i] == s[next_char])
                    next_char++;
                if(next_char >= s.size())
                    return s.substr(0, i);

                s[i] = s[next_char];
                s[next_char] = s[i-1];
                next_char++;
            } else
                char_count = (s[i-1] != s[i]) ? 1 : char_count + 1;
        }
        return s;
    }
};
