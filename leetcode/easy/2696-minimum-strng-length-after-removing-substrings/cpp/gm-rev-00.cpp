// Runtime: 5ms
// Memory: 10MB
class Solution {
public:
    int minLength(string s) {
        int ans = s.size();

        for(int i = 1; i < s.size(); i++) {
            if(s[i] != 'B' && s[i] != 'D')
                continue;
            int j = i - 1;
            while(j >= 0 && i < s.size()) {
                if(s[j] == '-')
                    j--;
                else if((s[i] == 'B' && s[j] == 'A') || (s[i] == 'D' && s[j] == 'C')) {
                    ans -= 2;
                    s[i++] = '-';
                    s[j--] = '-';
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
