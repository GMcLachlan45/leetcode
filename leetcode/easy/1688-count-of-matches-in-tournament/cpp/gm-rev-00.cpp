// Runtime: 0ms
// Memory: 6.26MB
class Solution {
public:
    int numberOfMatches(int n) {
        if(n==1)
            return 0;
        return n/2 + numberOfMatches(n-n/2);
    }
};
