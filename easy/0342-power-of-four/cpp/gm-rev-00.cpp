// Runtime 0ms
// Memory 6.26MB
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n==1 || n>0 && (log2(n)/log2(4) == (int) (log2(n)/log2(4)));
    }
};
