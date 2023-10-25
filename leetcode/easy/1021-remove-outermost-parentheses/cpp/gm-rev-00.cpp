// Runtime 3ms
// Memory 6.5MB
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ret = "";
        int layer = 0;
        for(char x: s) {
            if(x == '(') {
                if(layer)
                    ret.push_back(x);
                layer++;
            } else {
                layer--;
                if(layer)
                    ret.push_back(x);
            }
        }
        return ret;
    }
};
