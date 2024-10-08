// Runtime: 104ms
// Memory: 32.7MB
class Solution {
public:
    int minSwaps(string s) {
        int swaps = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] =='[')
                count++;
            else
                count--;
            if(count < 0) {
                swaps++;
                count = 1;
            }
        }

        return swaps;
    }
};
