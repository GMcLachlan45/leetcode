// Runtime: 4ms
// Memory: 6.4MB
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n) {
            ret += n%2;
            n >>= 1;
        }
        return ret;
    }
};
