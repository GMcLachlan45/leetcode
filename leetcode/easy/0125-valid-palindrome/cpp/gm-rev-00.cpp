// Runtime 4ms
// Memory 7.3MB
class Solution {
public:
    bool isPalindrome(string s) {
        short int end = s.length() - 1;
        short int start = 0;

        while(start < end) {
            if (!std::isalnum(s[start])) {
                start++;
            } else if (!std::isalnum(s[end])) {
                end--;
            } else {
                if(s[start]!=s[end] && (std::isdigit(s[start]) || std::isdigit(s[end]))){
                    std::cout << "here22";
                    return false;
                } else if (s[start] == s[end] || s[start] == s[end] + 32 || s[start] == s[end] - 32) {
                    start++;
                    end--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
