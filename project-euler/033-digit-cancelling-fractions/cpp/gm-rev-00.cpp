#include <string>
#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
#include <algorithm>

int main(int argc, char* argv[]) {
    // want denominotor > numerator
    // want numbers that contain at least 1 of the same number
    std::vector<std::pair<int,int>> fracs;
    for(int d = 11; d <= 99; d++) {
        if(d%10 == 0)
            continue;
        // Checking where Xn/nX
        for(int n = d/10 + 10; n < d; n+=10) {
            if((double)(n/10)/(d%10) == (double) n/d)
                fracs.push_back({n,d});
        }
        // Checking nX/Xn
        for(int n = d- d%10+1; n <d; n++) {
            if((double)(n%10)/(d/10) == (double) n/d)
                fracs.push_back({n,d});
        }
    }
    int numerator = 1;
    int denominator = 1;
    for(auto fraction : fracs) {
        numerator *= fraction.first;
        denominator *= fraction.second;
    }

    std::cout << "The simplified denominator of the product of these fractions is " << denominator/std::gcd(numerator,denominator)<<std::endl;
    return 0;
}
