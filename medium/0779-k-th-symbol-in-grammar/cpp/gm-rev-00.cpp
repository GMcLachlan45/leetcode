// Runtime 2ms
// Memory 6.56MB
class Solution {
public:
    int kthGrammar(int n, int k) {
        k--;
        int prevRowLength = std::pow(2, n-2);
        int flips = 0;
        while(k > 1){
            if(k+1>prevRowLength)
                flips++;
            k%=prevRowLength;
            prevRowLength/=2;
        }
        return k ^ (flips%2);
    }
};
