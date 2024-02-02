// Runtime: 0ms
// Memory: 7.73MB
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int digits = std::log10(low)+1;
        int maxDigits = std::log10(high)+1;
        int number;
        if((int) (low/std::pow(10, digits-1)) > 10 - digits){
            digits++;
            number = 1;
        } else
            number = low/std::pow(10, digits-1);
        for(int i = 1; i < digits; i++){
            number = number * 10 + (number%10 + 1);
        }
        if(number < low)
            number = (number % ((int) std::pow(10, digits-1)))*10 + (number%10 + 1);
        std::vector<int> ret;

        while(digits <= maxDigits) {
            while(number%10 && number%10 < 9) {
                if(number > high)
                    return ret;
                ret.push_back(number);
                number = (number % ((int) std::pow(10, digits-1)))*10 + (number%10 + 1);
            }
            if(number > high)
                return ret;
            if(number%10)
                ret.push_back(number);

            digits++;
            number = 1;
            for(int i = 1; i < digits; i++)
                number = number * 10 + (number%10 + 1);
        }
        return ret;
    }
};
