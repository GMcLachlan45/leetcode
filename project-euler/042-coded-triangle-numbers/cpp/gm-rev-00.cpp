#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

std::vector<int> readInputs(std::string filename) {
    std::ifstream myfile (filename);
    std::vector<int> ret;
    std::string input;
    if (myfile.is_open()) {
        while(getline(myfile, input)) {
            bool quotes = false;
            int number = 0;
            for(char c : input) {
                if(c == '"') {
                    if(number) {
                        ret.push_back(number);
                        number = 0;
                    }
                    quotes = !quotes;
                } else if(quotes)
                    number += c-'A'+1;
            }
        }
        myfile.close();
    } else {
        std::cout << "Don't forget the input";
    }
    return ret;
}

bool isTriangleNumber(int t_n) {
    // with quadratic formula, we want a double root that's an integer
    // triangle number t_n = (n(n+1)/2) => 2t_n = n^2+n
    //                                  => n^2+n-2t_n = 0
    double r_1 = (-1 + std::sqrt(1+8*t_n))/2;
    return r_1 == (int) r_1;
}

int main(int argc, char* argv[]) {
    std::vector<int> nums = readInputs(argv[1]);

    int count = 0;
    for(int i : nums) {
        if(isTriangleNumber(i))
            count++;
    }
    std::cout << "Solution: the number of triangle words in this set is: " << count << std::endl;
    return 0;
}
