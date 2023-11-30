// Runtime: 0ms
// Runtime: 6.2MB
class Solution {
    int helper(int n, bool evenBits) {
        if(n == 1)
            return 1;
        if(evenBits)
            return helper(n/2, evenBits^(n%2 == 1))*2;
        else
            return helper(n/2, evenBits^(n%2 == 1))*2+1;
    }

    bool findIfEvenNumberOfBits(int n) {
        int bitCount = 0;
        while(n>0) {
            bitCount += n%2;
            n >>=1;
        }
        return bitCount %2 == 0;
    }

public:
    int minimumOneBitOperations(int n) {
        if(n==0)
            return 0;
        return helper(n, findIfEvenNumberOfBits(n));
    }
};
