// Runtime 8ms
// Memory 7.7MB

class Solution {
public:
    vector<string> cellsInRange(string s) {
        std::vector<string> l;
        for(char c = s[0]; c <= s[3]; c++){
            for(char r = s[1]; r <= s[4]; r++){
                l.push_back( string("").append(1, c).append(1, r));
            }
        }
        return l;
    }
};
