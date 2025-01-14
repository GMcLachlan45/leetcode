// Runtime: 12ms
// Memory: 30MB
class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() & 1)
            return false;
        int min = 0;
        int max = 0;
        for(int i = 0; i < s.size(); i++) {
            if(locked[i] - '0') {
                if(s[i] == '(') {
                    min++;
                    max++;
                } else {
                    min--;
                    max--;
                }
            } else {
                min--;
                max++;
            }
            if(max < 0)
                return false;
        }
        if(min > 0)
            return false;

        min = 0;
        max = 0;
        for(int i = s.size()-1; i >= 0; i--) {
            if(locked[i] - '0') {
                if(s[i] == ')') {
                    min++;
                    max++;
                } else {
                    min--;
                    max--;
                }
            } else {
                min--;
                max++;
            }
            if(max < 0)
                return false;
        }
        return min <= 0;
    }
};
