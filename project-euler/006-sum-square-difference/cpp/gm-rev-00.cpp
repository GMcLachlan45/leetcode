#include <iostream>

int main(){
    long sum = 0;
    long squareSum = 0;
        for(int i = 1; i <= 100; i++) {
            sum += i;
            squareSum += i*i;
        }
        std::cout << sum*sum - squareSum << std::endl;

    return 0;
}
