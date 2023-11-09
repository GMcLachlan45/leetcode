// Runtime: 21ms
// Memory: 11.96MB
class Solution {
public:
    int countHomogenous(string s) {
        char letter = '.';
        int count = 0;
        int total = 0;
        int MOD = 1000000007;
        for(char c : s) {
            if(c != letter){
                letter = c;
                count = 1;
            }
            total = (total + count) % MOD;
            count++;
        }
        return total;
    }
};
