// Runtime: 3ms
// Memory: 7.7MB
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        goal ^= start;
        while(goal) {
            ans += goal % 2;
            goal >>= 1;
        }
        return ans;
    }
};
