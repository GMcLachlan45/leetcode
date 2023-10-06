// Runtime 0ms
// Memory 6.57MB
class Solution {
public:
    int integerBreak(int n) {
        int prod = 1;
        for(int i = 2; i < n; i++){
            int newprod = std::pow(n/i, i-n%i) * std::pow(n/i+1, n%i);
            if(prod < newprod)
                prod = newprod;
            else
                break;
        }
        return prod;
    }
};
