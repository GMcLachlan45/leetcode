#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>

std::vector<std::string> readInputs(std::string filepath) {
    std::ifstream infile(filepath.c_str());
    std::vector<std::string> ret;

    std::string line;
    while(std::getline(infile, line)) {
        ret.push_back(line);

    }
    return ret;
}

int main(int argc, char* argv[]) {

    std::vector<std::string> inputs = readInputs(argv[1]);

    int ans1 = 0;
    for(std::string input:inputs){
        for(int i = 0; i < input.size(); i++) {
            if(input[i] != 'm')
                continue;
            i++;
            if(input[i] != 'u')
                continue;
            i++;
            if(input[i] != 'l')
                continue;
            i++;
            if(input[i] != '(')
                continue;
            i++;
            if(!std::isdigit(input[i]))
                continue;
            int num1_start = i;
            while(std::isdigit(input[i]))
                i++;
            if(input[i] != ',')
                continue;
            i++;
            if(!std::isdigit(input[i]))
                continue;
            int num2_start = i;
            while(std::isdigit(input[i]))
                i++;
            if(input[i] != ')')
                continue;
            ans1 += std::stoi(input.substr(num1_start)) * std::stoi(input.substr(num2_start));
        }
    }
    std::cout << "Solution 1: The resulting value is "<<ans1<<std::endl;

    int ans2 = 0;
    bool on = true;
    for(std::string input:inputs){
        for(int i = 0; i < input.size(); i++) {
            if(!on){
                if(i < input.size() - 4
                   && input[i] == 'd' && input[i+1] == 'o'&& input[i+2] == '(' && input[i+3] == ')'){
                    on = true;
                }
                continue;
            }
            if(i < input.size()-6
               && input[i] == 'd' && input[i+1] == 'o' && input[i+2] == 'n' && input[i+3] == '\'' && input[i+4] == 't' && input[i+5] == '(' && input[i+6] == ')') {
                on = false;
                continue;
            }
            if(input[i] != 'm')
                continue;
            i++;
            if(input[i] != 'u')
                continue;
            i++;
            if(input[i] != 'l')
                continue;
            i++;
            if(input[i] != '(')
                continue;
            i++;
            if(!std::isdigit(input[i]))
                continue;
            int num1_start = i;
            while(std::isdigit(input[i]))
                i++;
            if(input[i] != ',')
                continue;
            i++;
            if(!std::isdigit(input[i]))
                continue;
            int num2_start = i;
            while(std::isdigit(input[i]))
                i++;
            if(input[i] != ')')
                continue;
            ans2 += std::stoi(input.substr(num1_start)) * std::stoi(input.substr(num2_start));
        }
    }

    // Passed
    std::cout << "Solution 2: The resulting value is "<<ans2<<std::endl;

}
