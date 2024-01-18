// Runtime: 0ms
// Memory: 6.24MB
class Solution {
public:
    int climbStairs(int n) {
        int current = 1;
        int nextStair = 0;
        for(int i = 0; i < n; i++) {
            int nextNextStair = 0;
            nextStair += current;
            nextNextStair += current;
            current = nextStair;
            nextStair = nextNextStair;
        }
        return current;
    }
};
