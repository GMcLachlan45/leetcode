// Runtime 73ms
// Memory 22MB
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        std::vector<string> list;
        for(int denominator = 1; denominator <= n; denominator++) {
            for(int numerator = 1; numerator < denominator; numerator++) {
                if(std::gcd(numerator, denominator) == 1)
                    list.push_back(to_string(numerator) + "/" + to_string(denominator));
            }
        }
        return list;
    }
};
