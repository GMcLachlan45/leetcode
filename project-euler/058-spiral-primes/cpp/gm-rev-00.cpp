#include <string>
#include <iostream>

// Shamelessly stolen from Stack Overflow
bool isPrime(int number) {
    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    // Starting at 3 in the top right corner of length 3
    int value = 3;
    int squareLength = 3;
    int cornerCount = 0;

    int primeCount = 0;
    int numberCount = 1;
    while(true) {
        if(isPrime(value))
            primeCount++;
        numberCount++;
        if(cornerCount == 3) {
            if(primeCount * 10 < numberCount)
                break;
            squareLength+=2;
            cornerCount = 0;
        } else
            cornerCount++;
        value+= squareLength-1;
    }
    std::cout << "The length of the square where the prime count falls below 10% is " << squareLength <<std::endl;
    return 0;
}
