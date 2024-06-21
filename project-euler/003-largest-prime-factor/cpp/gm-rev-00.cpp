#include <vector>
#include <iostream>
#include <string>


int main() {
    long num = 600851475143;
    long tryNum = 2;
    while(num > tryNum){
        if(! (num % tryNum)) {
            std::cout<< tryNum <<std::endl;
            num /= tryNum;
            tryNum = 2;
        } else
            tryNum++;
    }
    std::cout<<"The largest prime factor is " <<num<<std::endl;
    return 0;
}
