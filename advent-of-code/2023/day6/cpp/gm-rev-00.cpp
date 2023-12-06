#include <string>
#include <iostream>
#include <vector>
#include "../../../bin/input-reader.cpp"
#include <cctype>
#include <cmath>
#include <utility>

std::vector<int> getNums(std::string in) {
    std::vector<int> vec;
    std::string num ="";
    for(char c: in) {
        if(std::isdigit(c))
            num += c;
        else{
            if(num!="")
                vec.push_back(std::stoi(num));
            num = "";
        }
    }
    vec.push_back(std::stol(num));
    return vec;
}

long winningRange(long time, long distance) {
    double r_1 = (-time + std::sqrt(time *time  -4*distance))/(-2);
    double r_2 = (-time - std::sqrt(time *time  -4*distance))/(-2);
    if((int) r_1 == r_1)
        r_1 += 1;
    if((int) r_2 == r_2)
        r_2 -= 1;
    return std::floor(r_2) - std::ceil(r_1) + 1;

}

int main(int argc, char* argv[]) {
    std::vector<std::string> input = readInputs(argv[1]);
    std::vector<int> time = getNums(input[0]);
    std::vector<int> distance = getNums(input[1]);
    // Want to find where heldtime(time-heldtime) >= distance
    // r(t-r) >= d   ==>   -r^2+rt-d > 0
    // so we find the roots, and find the whole numbers
    int error = 1;
    std::string realTime = "";
    std::string realDistance = "";
    for(int i = 0; i < time.size(); i++) {
        realTime += std::to_string(time[i]);
        realDistance += std::to_string(distance[i]);
        error *= winningRange(time[i], distance[i]);
    }
    std::cout<< "Solution 1: margin of error is: " << error << std::endl;
    std::cout<< "Solution 2: the actual margin of error is " << winningRange(std::stol(realTime), std::stol(realDistance)) << std::endl;

    return 0;

}
