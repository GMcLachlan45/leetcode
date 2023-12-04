#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../../bin/input-reader.cpp"
#include <cctype>

bool symbolNearby(int startX, int startY, int endX, int endY, std::vector<std::string> in) {
    if(startX<0)
        startX++;
    if(startY<0)
        startY++;
    for(int y = startY; y <=endY; y++) {
        for(int x = startX; x <= endX; x++) {
            if(!std::isdigit(in[y][x]) && in[y][x] != '.')
                return true;
        }
    }
    return false;
}

std::string gearNearby(int startX, int startY, int endX, int endY, std::vector<std::string> in) {
    if(startX<0)
        startX++;
    if(startY<0)
        startY++;
    for(int y = startY; y <=endY; y++) {
        for(int x = startX; x <= endX; x++) {
            if(in[y][x] == '*')
                return std::to_string(x) +" "+std::to_string(y);
        }
    }
    return "";
}

int main(int argc, char* argv[]) {
    std::vector<std::string> inputs = readInputs(argv[1]);
    int sum = 0;
    std::unordered_map<std::string, int> ratios;
    int ratioSum = 0;
    for(int i = 0; i < inputs.size(); i++) {
        int numberStart = -1;
        for(int j = 0; j < inputs[i].size(); j++) {
            if(std::isdigit(inputs[i][j])) {
                if(numberStart == -1)
                    numberStart = j;
            } else if(numberStart != -1) {
                if(symbolNearby(numberStart-1, i-1, j, (i==inputs.size()-1) ? i: i+1, inputs)){
                    sum += std::stoi(inputs[i].substr(numberStart, j-numberStart));
                    std::string gear = gearNearby(numberStart-1, i-1, j, (i==inputs.size()-1) ? i: i+1, inputs);
                    if(gear!="") {
                        if(ratios[gear])
                            ratioSum += ratios[gear] * std::stoi(inputs[i].substr(numberStart, j-numberStart));
                        else
                            ratios[gear] = std::stoi(inputs[i].substr(numberStart, j-numberStart));
                    }


                }
               numberStart = -1;
            }

            if(numberStart != -1 && j == inputs[i].size() - 1) {
                if(symbolNearby(numberStart-1, i-1, inputs[i].size() - 1, (i==inputs.size()-1) ? i: i+1, inputs)){
                    sum += std::stoi(inputs[i].substr(numberStart, j-numberStart+1));
                    std::string gear = gearNearby(numberStart-1, i-1, j, (i==inputs.size()-1) ? i: i+1, inputs);
                    if(gear!="") {
                        if(ratios[gear])
                            ratioSum += ratios[gear] * std::stoi(inputs[i].substr(numberStart, j-numberStart+1));
                        else
                            ratios[gear] = std::stoi(inputs[i].substr(numberStart, j-numberStart+1));
                    }

                }
            }
        }
    }
    // Passed
    std::cout << "Solution 1: the sum of all the part numbers is " << sum <<std::endl;
    // Passed
    std::cout << "Solution 2: the sum of the gear ratios is " << ratioSum <<std::endl;
    return 0;
}
