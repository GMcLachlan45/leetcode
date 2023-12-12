#include <numeric>
#include <iostream>
int main() {
    int mult = 1;
    int upperBound = 20;
    for(int i = 2; i <= upperBound; i++){
        mult = std::lcm(mult, i);
    }

    std::cout <<  mult << std::endl;
    return 0;
}
