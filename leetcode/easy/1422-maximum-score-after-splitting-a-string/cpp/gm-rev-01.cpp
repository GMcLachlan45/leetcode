// Runtime: 3ms
// Memory: 8.7MB
class Solution {
public:
    int maxScore(string s) {
        int zeros_in_left = s[0] == '0';
        int ones_in_right = -(s[0] == '1');
        for(char c : s)
            ones_in_right += c  == '1';

        int ans = ones_in_right;

        for(int i = 1; i < s.size(); i++) {
            if(ans < zeros_in_left + ones_in_right)
                ans = zeros_in_left + ones_in_right;
            if(s[i] == '0')
                zeros_in_left++;
            else
                ones_in_right--;
        }

        return ans;
    }
};
