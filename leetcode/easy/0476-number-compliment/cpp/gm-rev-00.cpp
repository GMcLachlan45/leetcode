// Runtime: 0ms
// Memory: 7.5MB
class Solution {
public:
    int findComplement(int num) {
        unsigned int number = num;
        int powerOfTwo = 1;
        while(powerOfTwo <= number){
            number = number ^ powerOfTwo;
            powerOfTwo <<= 1;
        }
        return number;
    }
};
