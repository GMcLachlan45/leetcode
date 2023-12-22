// Memory: 6.61MB
// Runtime: 3ms

class Solution {
public:
    int maxScore(string s) {
        int max = 0;
        int ones = 0;
        for(char c : s)
            if(c =='1')
                ones++;

        int passedZeros = 0;
        int passedOnes = 0;
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] == '0')
                passedZeros++;
            else
                passedOnes++;
            max = std::max(max, passedZeros + ones-passedOnes);
        }
        return max;
    }
};
