#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

void printMedian(std::stringstream s) {
    std::vector<float> nums;
    std::string element;

    while(s >> element) {
        nums.push_back(std::stof(element));
        std::sort(nums.begin(), nums.end());
        if(nums.size() % 2)
            std::cout << nums[(nums.size()-1)/2];
        else
            std::cout << (nums[(nums.size()-1)/2] + nums[(nums.size()-1)/2 + 1])/2;
        std::cout << std::endl;
    }
}

int main() {
    std::string str = "100 55 20 9 8 7 6 5 4 3 2 1 0";
    std::cout << "For the stream " << str << std::endl;
    printMedian(std::stringstream(str));

    str = "2 1 5 7 2 0 5";
    std::cout << "For the stream " << str << std::endl;
    printMedian(std::stringstream(str));
}
