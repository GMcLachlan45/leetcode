#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include "../../../bin/input-reader.cpp"
#include <cctype>
#include <cmath>

int main(int argc, char* argv[]) {
    std::vector<std::string> inputs = readInputs(argv[1]);
    int pointSum = 0;
    int cardCount = 0;
    std::vector<int> numberOfCards(inputs.size(), 1);


    for(int i = 0; i < inputs.size(); i++) {
        bool passedColon = false;
        bool passedPipe = false;
        std::unordered_set<int> winningNumbers;
        int numStart = -1;
        int currentMatches = 0;
        cardCount += numberOfCards[i];
        for(int j = 0; j <= inputs[i].size(); j++) {
            if(!passedColon){
                passedColon = inputs[i][j] == ':';
                continue;
            }
            if(!std::isdigit(inputs[i][j])){
                if(!passedPipe)
                    passedPipe = inputs[i][j] == '|';
                continue;
            }
            numStart = j;
            while(j<inputs[i].size() && std::isdigit(inputs[i][j]))
                j++;
            int number = std::stoi(inputs[i].substr(numStart, j-numStart));
            if(passedPipe && winningNumbers.count(number))
                currentMatches++;
            else
                winningNumbers.insert(number);
        }

        if(currentMatches) {
            pointSum += std::pow(2, currentMatches-1);
            while(currentMatches > 0) {
                if(i + currentMatches < numberOfCards.size())
                    numberOfCards[i+currentMatches] += numberOfCards[i];
                currentMatches--;
            }
        }
    }
    // Passed
    std::cout << "Solution 1: the sum of all the points we have are " << pointSum <<std::endl;
    // Passed
    std::cout << "Solution 2: the number of cards we have in total are " << cardCount <<std::endl;
    return 0;
}
