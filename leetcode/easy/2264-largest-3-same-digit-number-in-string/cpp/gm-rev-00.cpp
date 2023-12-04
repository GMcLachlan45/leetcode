// Runtime: 0ms
// Memory: 6.93MB
class Solution {
public:
    string largestGoodInteger(string num) {
        char largestDigit ='0'-1;
        for(int i = 0; i < num.size(); i++) {
            int firstNum = i;
            while(i < num.size() && num[firstNum] == num[i])
                i++;
            if(i - firstNum > 2 && (num[firstNum] > largestDigit))
                largestDigit = num[firstNum];
            i--;
        }
        if(largestDigit < '0')
            return "";
        return std::string(3, largestDigit);
    }
};
