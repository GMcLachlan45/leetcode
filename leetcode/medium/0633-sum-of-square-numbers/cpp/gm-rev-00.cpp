// Runtime: 3ms
// Memory: 7.06MB
class Solution {
public:
    bool judgeSquareSum(int c) {
        int b = (int) std::sqrt(c);
        int a = 0;
        while(a <= b) {
            long val = (long) a*a + (long) b*b;
            if(val == c)
                return true;
            else if(val < c)
                a++;
            else
                b--;
        }
        return false;
    }
};
