#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

std::string randomStreamElement(std::stringstream s) {
    std::string returned_element;
    std::string element;
    int elementCount = 1;

    while(s >> element)
        if((double) std::rand() / RAND_MAX <= 1.0/elementCount++)
            returned_element = element;
    return returned_element;
}

#include <map>
void printDistribution(std::string s, int reps) {
    std::map<std::string, int> occurences;
    for(int i = 0; i < reps; i++)
        occurences[randomStreamElement(std::stringstream(s))]++;

    for(auto x : occurences)
        std::cout<< x.first <<": " << ((double) x.second / reps)<<std::endl;
}

int main() {
    std::string str = "0 1 2 3 4 5 6 7 8 9 a b c d e f g h i j";
    std::cout << "A random element from the given stream is " << randomStreamElement(std::stringstream(str)) << std::endl;

    int k = 1000;
    std::cout << "And for proof that it's uniform, we repeat "<< k<<" times and get the distribution:"<<std::endl;
    printDistribution(str, k);

    k = 10000;
    std::cout << "And for proof that it's uniform, we repeat "<< k<<" times and get the distribution:"<<std::endl;
    printDistribution(str, k);

    k = 100000;
    std::cout << "And for proof that it's uniform, we repeat "<< k<<" times and get the distribution:"<<std::endl;
    printDistribution(str, k);

    k = 1000000;
    std::cout << "And for proof that it's uniform, we repeat "<< k<<" times and get the distribution:"<<std::endl;
    printDistribution(str, k);

}
