#include <string>
#include <iostream>
#include <vector>
#include "../../../bin/input-reader.cpp"

int northPlusLoad(std::vector<std::string> input) {
    int ans = 0;
    int cols = input[0].size();
    int rows = input.size();

    for(int col = 0; col < cols; col++) {
        int hardRock = 0;
        for(int row = 0; row < rows; row++) {
            if(input[row][col] =='#') {
                hardRock = row+1;
            } else if(input[row][col] =='O') {
                ans += rows-hardRock;
                hardRock++;
            }
        }

    }
    return ans;

}
int calculateLoad(std::vector<std::string> input) {
    int ans = 0;
    int cols = input[0].size();
    int rows = input.size();

    for(int col = 0; col < cols; col++) {
        for(int row = 0; row < rows; row++) {
            if(input[row][col] =='O') {
                ans += rows-row;
            }
        }

    }
    return ans;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> input = readInputs(argv[1]);
    std::vector<std::vector<std::string>> ins;
    std::vector<std::string> in;
    for(std::string line: input) {
        if(line==""){
            ins.push_back(in);
            in.clear();
        } else {
            in.push_back(line);
        }
    }
    ins.push_back(in);
    // Passes
    std::cout<< "Solution 1: the load after pushing the rocks north is " << northPlusLoad(ins[0])<<std::endl;
    // Where we use cc.txt that has all of the possible states
    std::cout <<"Solution 2: for my input, the load after the cycles is "<< calculateLoad(ins[109])<<std::endl;
    return 0;
}
