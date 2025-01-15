// Runtime: 0ms
// Memory: 8.14MB
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits = 0;
        while(num2) {
            if(1 & num2)
                bits++;
            num2 >>=1;
        }
        int ans = 0;
        for(int bit = 1 << 30; bits && bit > 0; bit >>=1) {
            if(bit & num1) {
                ans |= bit;
                bits--;
            }
        }
        for(int bit = 1; bits; bit <<= 1) {
            if(!(bit & num1)) {
                ans |= bit;
                bits--;
            }
        }
        return ans;
    }
};
