// Runtime 0ms 
// Memory 6.2MB
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == goal[0]) {
                bool success = true;
                for(int j = 0; success && j < goal.size(); j++) 
                    success = s[(i+j)%s.size()] == goal[j];
                if(success)
                    return true;
            }
        }
        return false;
    }
};
