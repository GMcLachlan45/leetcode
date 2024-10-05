#include <iostream>
#include <cstdlib>
#include <ctime>

double approximatePi() {
    std::srand(std::time(nullptr));
    int inCircle = 0;
    int total = 10000000;
    for(int i = 0; i < total ; i++) {
        double x = ((double)std::rand()/ RAND_MAX);
        double y = ((double)std::rand()/ RAND_MAX);
        if(x*x + y*y < 1)
            inCircle++;
    }
    return (double) inCircle / total * 4;
}
int main() {
    std::cout<< "An approximation for Pi to 3 decimal places is " << approximatePi()<<std::endl;
}
