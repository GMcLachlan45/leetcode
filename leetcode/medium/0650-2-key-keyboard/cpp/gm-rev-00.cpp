// Runtime: 3ms
// Memory: 7.5MB
class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;

        int greatestDivisor = 1;
        for(int i = 2; i < n/2; i++)
            if(n%i == 0) {
                greatestDivisor = n/i;
                break;
            }

        if(greatestDivisor == 1)
            return n;
        return minSteps(greatestDivisor) + n/greatestDivisor;
    }
};
