// Runtime: 3ms
// Memory: 7.4MB
class Solution {
public:
    int minBitFlips(int start, int goal) {
        goal ^= start;
        int ans = 0;
        for(int check = 1; check <= goal; check <<= 1)
            if(goal & check)
                ans++;
        return ans;
    }
};
