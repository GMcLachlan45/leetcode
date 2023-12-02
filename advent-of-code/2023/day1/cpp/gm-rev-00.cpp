#include <string>
#include <iostream>
#include <vector>
#include "../../../bin/input-reader.cpp"


char findDigit(std::string in) {
    if(in[0] =='o')
        return (in[1] == 'n' && in[2] =='e') ? '1': 0;
    else if(in[0] == 't') {
        if(in[1] == 'w')
            return (in[2] == 'o') ? '2': 0;
        else
            return (in[1] == 'h' &&in[2] == 'r' &&in[3] == 'e' &&in[4] == 'e') ? '3': 0;
    } else if(in[0] == 'f') {
        if(in[1] == 'i')
            return (in[2] == 'v' && in[3] == 'e') ? '5': 0;
        else
            return (in[1] == 'o' && in[2] == 'u' && in[3] == 'r') ? '4': 0;
    } else if(in[0] == 's') {
        if(in[1] == 'e')
            return (in[2] == 'v' && in[3] == 'e'&& in[4] == 'n') ? '7': 0;
        else
            return (in[1] == 'i' && in[2] == 'x') ? '6': 0;
    } else if((in[0] == 'n' && in[1] == 'i'&& in[2] == 'n'&& in[3] == 'e'))
        return '9';
    else if((in[0] == 'e' && in[1] == 'i'&& in[2] == 'g'&& in[3] == 'h'&& in[4] == 't'))
        return '8';
    return 0;
}


int main() {
    std::cout << "Hello AoC 2023!" << std::endl;
    std::vector<std::string> inputs = readInputs();
    int calibration = 0;
    for(std::string input : inputs) {
        char firstNumber = 0;
        char secondNumber = 0;
        for(int i = 0; (!firstNumber || !secondNumber) && i < input.size(); i++) {
            if(!firstNumber) {
                if(input[i] <='9' && input[i] >='0')
                    firstNumber = input[i];
                else
                    firstNumber = findDigit(input.substr(i, 5));
            }
            if(!secondNumber) {
                if(input[input.size()-1-i] <='9' && input[input.size()-1-i] >='0')
                    secondNumber = input[input.size()-1-i];
                else
                    secondNumber = findDigit(input.substr(input.size()-1-i, 5));
            }
        }
        calibration += (firstNumber-'0')*10 + secondNumber-'0';
    }
    // Passed
//    std::cout << "Solution 1: The sum of the calibration values is "<<calibration<<std::endl;
    // Passed...
    std::cout << "Solution 2: The sum of the REAL calibration values is "<<calibration<<std::endl;
    return 0;
}
