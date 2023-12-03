#include <string>
#include <iostream>
#include <vector>
#include "../../../bin/input-reader.cpp"
#include <cctype>
int main(int argc, char* argv[]) {
    std::vector<std::string> inputs = readInputs(argv[1]);
    // array with the elf's requested red, green and blue cubes
    int maxColors[] = {12,13,14};
    long long possibleGames = 0;
    long long cubePowerSum = 0;
    for(int i = 0; i < inputs.size(); i++) {
        bool pastColon = false;
        bool gamePossible = true;
        int minPossibleColors[] = {0,0,0};
        for(int ptr = 0; ptr < inputs[i].size(); ptr++) {
            if(!pastColon) {
                pastColon = inputs[i][ptr] == ':';
                continue;
            }
            if(std::isdigit(inputs[i][ptr])) {
                int digitStart = ptr;
                while(std::isdigit(inputs[i][ptr]))
                    ptr++;
                int cubeValue = std::stoi(inputs[i].substr(digitStart,ptr-digitStart));
                if(inputs[i][ptr+1] == 'r') {
                    if(minPossibleColors[0] < cubeValue)
                        minPossibleColors[0] = cubeValue;
                    if(cubeValue > maxColors[0])
                        gamePossible = false;
                    else
                        ptr += 4;
                } else if (inputs[i][ptr+1] == 'g') {
                    if(minPossibleColors[1] < cubeValue)
                        minPossibleColors[1] = cubeValue;
                    if(cubeValue > maxColors[1])
                        gamePossible = false;
                    else
                        ptr += 6;
                } else {
                    if(minPossibleColors[2] < cubeValue)
                        minPossibleColors[2] = cubeValue;
                    if(cubeValue > maxColors[2])
                        gamePossible = false;
                    else
                        ptr += 5;
                }
            }
        }
        cubePowerSum += minPossibleColors[0]*minPossibleColors[1]*minPossibleColors[2];
        if(gamePossible){
            possibleGames += i+1;
        }
    }
    // Passed
    std::cout << "Solution 1: The sum of the games possible under such restraints is " << possibleGames<<std::endl;
    // Passed
    std::cout << "Solution 2: The sum of the minimum cube power is " << cubePowerSum << std::endl;
    return 0;
}
