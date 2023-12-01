#include <string>
#include <iostream>
// A helper function to easily read the player's input
#include "../../../bin/input-reader.cpp"
int main() {
    std::cout<< "Hello AoC 2015!"<< std::endl;
    std::string input= readInput();
    int floor = 0;
    int firstBasement = -1;
    for(int i = 0; i < input.size(); i++) {
        if(input[i]=='(')
            floor++;
        else {
            floor--;
            if(firstBasement == -1 && floor < 0)
                firstBasement = i+1;
        }
    }
    // Passed
    std::cout<< "Solution to part 1: Santa's final floor is floor "<< floor << std::endl;
    // Passed
    std::cout<< "Solution to part 2: Santa is in the basement after "<< firstBasement << " steps" << std::endl;
    return 0;
}
