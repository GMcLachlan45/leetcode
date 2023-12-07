// Runtime: 26ms
// Memory: 15.35MB
class Solution {
public:
    string largestOddNumber(string num) {
        int lastOdd =-1;
        for(int i = num.size()-1; lastOdd == -1 && i >=0; i--) {
            if(num[i]%2)
                lastOdd = i;
        }
        return num.substr(0, lastOdd+1);
    }
};
