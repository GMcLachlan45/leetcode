#include <iostream>
#include <vector>
int main() {
    std::vector<unsigned long long> primes;
    unsigned long long i = 2;
    while(primes.size() < 10001) {
        bool isPrime = true;
        for(unsigned long long prime : primes) {
            if(i%prime == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            primes.push_back(i);
        i++;
    }

    std::cout<<"The 10001st prime number is " << primes[10000]<<std::endl;
    return 0;
}
