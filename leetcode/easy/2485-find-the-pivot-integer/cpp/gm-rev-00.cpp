// Runtime: 0ms
// Memory: 8.1MB
class Solution {
public:
    int pivotInteger(int n) {
        int r = 0;
        for(int i = 1; i <= n; i++)
            r += i;
        int l = 0;
        for(int i = 1; i <= n; i++) {
            l += i;
            if(l == r)
                return i;
            if(l > r)
                break;
            r-= i;
        }
        return -1;
    }
};
