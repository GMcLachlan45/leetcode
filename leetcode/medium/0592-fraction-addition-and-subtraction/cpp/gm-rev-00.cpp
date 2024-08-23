// Runtime: 3ms
// Memory: 7.9MB
class Solution {
public:
    string fractionAddition(string expression) {
        int ans = 0;
        int lptr = 0;
        int rptr = 1;
        while(rptr < expression.size()) {
            while(std::isdigit(expression[rptr]))
                rptr++;
            int numerator = std::stoi(expression.substr(lptr, rptr-lptr));
            lptr = 1 + rptr++;

            while(std::isdigit(expression[rptr]))
                rptr++;
            int denominator = std::stoi(expression.substr(lptr, rptr-lptr));
            lptr = rptr++;

            // Add to the ans with the common denominator: 10!
            ans += (3628800/denominator) * numerator;
        }
        int greatestDenominator = std::gcd(ans, 3628800);
        return ""+std::to_string(ans/greatestDenominator)+"/"+ std::to_string(3628800/greatestDenominator);
    }
};
