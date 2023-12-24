// Runtime: 6ms
// Memory: 7.34MB
class Solution {
public:
    int minOperations(string s) {
        int zeroOne = 0;
        int oneZero = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i%2) {
                if(s[i] == '0')
                    zeroOne++;
                else
                    oneZero++;
            } else {
                if(s[i] == '1')
                    zeroOne++;
                else
                    oneZero++;
            }
        }
        return std::min(zeroOne, oneZero);
    }
};
