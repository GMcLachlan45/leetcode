// Runtime 0ms
// Memory 6MB
class Solution {
public:
    int totalMoney(int n) {
        short int w = n/7;
        short int d = n%7;
        int sum = w * 28;
        while(d > 0){
            sum += d + w;
            d--;
        }

        w--;
        while(w > 0){
            sum += 7 * w;
            w--;
        }
        return sum;
    }
};