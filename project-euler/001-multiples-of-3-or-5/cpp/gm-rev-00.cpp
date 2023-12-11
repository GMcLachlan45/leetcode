#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    int threes = 3;
    int fives = 5;
    int sum = 0;
    while(threes<1000) {
        sum += threes;
        threes += 3;
    }
    while(fives<1000) {
        if(fives % 3)
            sum += fives;
        fives += 5;
    }
    std::cout << "The sum of all these multiples is " << sum <<std::endl;
    return 0;
}
