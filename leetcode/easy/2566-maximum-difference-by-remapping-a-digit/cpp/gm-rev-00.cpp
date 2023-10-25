// Runtime 4ms
// Memory 6.3MB
class Solution {
public:
    int minMaxDifference(int num) {
        int power_of_10 =  (int) std::pow(10.0, (int) std::log10(num));
        int first = num / power_of_10;
        int first_non_9 = first;
        for(int digit = 0; power_of_10 > 0; power_of_10 /= 10){
            digit = num / power_of_10 % 10;

            if(first_non_9 == 9 && digit != 9)
                first_non_9 = digit;
            
            if(digit == first_non_9)
                num += (9 - first_non_9) * power_of_10;

            if(digit != first)
                num -= digit * power_of_10; 
        }
        return num;
    }
};