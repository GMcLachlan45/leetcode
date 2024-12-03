#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

std::vector<std::vector<int>> readInputs(std::string filepath) {
    std::ifstream infile(filepath.c_str());

    std::vector<std::vector<int>> ret;

    std::string line;
    while(std::getline(infile, line)) {
        ret.push_back({});
        std::stringstream istr(line);
        int a;
        while(istr >> a)
            ret[ret.size()-1].push_back(a);
    }
    return ret;
}

int main(int argc, char* argv[]) {

    std::vector<std::vector<int>> inputs = readInputs(argv[1]);
    int safe_reports = 0;
    for(auto report : inputs) {
        bool safe = true;
        bool inc = report[1] > report[0];
        for(int i = 1; safe && i < report.size(); i++) {
            if(inc) {
                safe &= report[i] > report[i-1] && (report[i] - report[i-1] > 0 && report[i] - report[i-1] <= 3);
            } else {
                safe &= report[i] < report[i-1] && (report[i-1] - report[i] > 0 && report[i-1] - report[i] <= 3);
            }
        }
        safe_reports += safe;
    }
    // Passed
    std::cout << "Solution 1: The number of safe reports is  "<<safe_reports<<std::endl;

    safe_reports = 0;
    for(auto report : inputs) {
        for(int skip = 0; skip < report.size(); skip++) {
            bool safe = true;
            int last = 0 +(skip == 0);
            for(int i = 1+(skip == 0); safe && i < report.size(); i++) {
                if(i == skip)
                    continue;
                safe &= report[i] > report[last] && (report[i] - report[last] > 0 && report[i] - report[last] <= 3);
                last = i;
            }
            if(safe) {
                safe_reports++;
                break;
            }
            safe = true;
            last = report.size()-1 -(skip == report.size()-1);
            for(int i = report.size()-2 - (skip == report.size()-1); safe && i >=0+(skip == 0); i--) {
                if(i == skip)
                    continue;
                safe &= report[i] > report[last] && (report[i] - report[last] > 0 && report[i] - report[last] <= 3);
                last = i;
            }
            if(safe) {
                safe_reports++;
                break;
            }
        }
    }

    // Passed... O(n^2) baybee
    std::cout << "Solution 2: The actual number of safe reports is " << safe_reports<<std::endl;
}
