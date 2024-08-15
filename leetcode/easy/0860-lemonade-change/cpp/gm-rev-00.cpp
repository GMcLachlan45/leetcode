// Runtime: 81ms
// Memory: 86MB
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        /* you are the one with a meme degree */
        int fives = 0;
        int tens = 0;
        for(int bill: bills)
            switch(bill) {
            case 20:
                tens--;
                fives--;
                if(tens < 0) {
                    tens++;
                    fives -= 2;
                }
                if(fives <0)
                    return false;
                break;
            case 10:
                tens++;
                fives--;
                if(fives <0)
                    return false;
                break;
            default:
                fives++;
            }
        return true;
    }
};
