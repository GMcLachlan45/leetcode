#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

std::vector<std::vector<int>> readInputs(std::string filepath) {
    std::ifstream infile(filepath.c_str());
    std::vector<std::string> ret;

    std::string line;
    while(std::getline(infile, line)) {
        if(line =="")
            break;
        ret.push_back(line);
    }
    return ret;
}

int main(int argc, char* argv[]) {

    std::vector<std::string> input = readInputs(argv[1]);

    int ans1 = 0;
    std::queue<std::vector<int>> q;
    for(int row = 0; row < input.size(); row++) {
        for(int col = 0; col < input[row].size(); col++) {
            if(input[row][col] == 'X') {
                q.push({'X', row, col, -1, -1});
                q.push({'X', row, col, -1, 0});
                q.push({'X', row, col, -1, 1});
                q.push({'X', row, col, 0, -1});
                q.push({'X', row, col, 0, 1});
                q.push({'X', row, col, 1, -1});
                q.push({'X', row, col, 1, 0});
                q.push({'X', row, col, 1, 1});
            }
        }
    }
    while(q.size()) {
        if( q.front()[1] >= 0 && q.front()[1] < input.size()
            && q.front()[2] >= 0 && q.front()[2] < input[0].size()
            && q.front()[0] == input[q.front()[1]][q.front()[2]]) {
            q.front()[1] += q.front()[3];
            q.front()[2] += q.front()[4];
            switch(q.front()[0]) {
            case 'X': q.front()[0] = 'M';
                q.push(q.front());
                break;
            case 'M':q.front()[0] = 'A';
                q.push(q.front());
                break;
            case 'A':q.front()[0] = 'S';
                q.push(q.front());
                break;
            case 'S':
                ans1++;
                break;
            }
        }
        q.pop();
    }


    // Passed
    std::cout << "Solution 1: The resulting value is "<<ans1<<std::endl;

    int ans2 = 0;
    for(int row = 1; row < input.size()-1; row++) {
        for(int col = 1; col < input[row].size()-1; col++) {
            if(input[row][col] != 'A')
                continue;
            if(input[row-1][col-1] =='S') {
                if(input[row+1][col+1] != 'M')
                    continue;
            } else if(input[row-1][col-1] =='M') {
                if(input[row+1][col+1] != 'S')
                    continue;
            } else
                continue;

            if(input[row+1][col-1] =='S') {
                if(input[row-1][col+1] != 'M')
                    continue;
            } else if(input[row+1][col-1] =='M') {
                if(input[row-1][col+1] != 'S')
                    continue;
            } else
                continue;
            ans2++;
        }
    }
    // Passed
    std::cout << "Solution 2: The resulting value is "<<ans2<<std::endl;

}
