// Runtime: 0ms
// Memory: 7.66MB
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        for(int i = 0; i < s.size(); i++) {
            int j = 0;
            while(j < goal.size() && s[(i + j)%s.size()] == goal[j])
                j++;
            if(j == s.size())
                return true;
        }
        return false;
    }
};
