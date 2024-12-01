#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

std::vector<std::vector<int>> readInputs(std::string filepath) {
    std::ifstream infile(filepath.c_str());
    int a, b;
    std::vector<std::vector<int>> ret = {{},{}};
    while(infile >> a >> b) {
        ret[0].push_back(a);
        ret[1].push_back(b);
    }
    return ret;
}

int main(int argc, char* argv[]) {
    std::cout << "Hello AoC 2024!" << std::endl;
    std::vector<std::vector<int>> inputs = readInputs(argv[1]);

    std::sort(inputs[0].begin(), inputs[0].end());
    std::sort(inputs[1].begin(), inputs[1].end());
    int ans1 = 0;
    for(int i = 0; i < inputs[0].size(); i++)
        ans1 += (inputs[0][i] < inputs[1][i]) ? inputs[1][i] - inputs[0][i] : inputs[0][i] - inputs[1][i];
    // Passed
    std::cout << "Solution 1: The sum of the distances of the numbers is  "<<ans1<<std::endl;

    int ans2 = 0;
    std::unordered_map<int,int> mp;
    for(auto x : inputs[0])
        mp[x]++;
    for(auto y : inputs[1])
        ans2 += y*mp[y];
    // Passed
    std::cout << "Solution 2: The sum of the similarities of the numbers is " << ans2<<std::endl;
}
