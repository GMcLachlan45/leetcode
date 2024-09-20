// Runtime: 231ms
// Memory: 9.4MB
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size() < 2)
            return s;
        int end_ptr = s.size()-1;
        std::string ans;
        while(ans.size() == 0) {
            int front_check = 0;
            int back_check = end_ptr;
            bool valid = s[front_check] == s[back_check];
            while(front_check < back_check && valid)
                valid = s[++front_check] == s[--back_check];

            if(valid) {
                ans = s.substr(end_ptr+1, s.size() - end_ptr - 1);
                std::reverse(ans.begin(), ans.end());
                ans += s;
            }
            end_ptr--;
        }
        return ans;
    }
};
