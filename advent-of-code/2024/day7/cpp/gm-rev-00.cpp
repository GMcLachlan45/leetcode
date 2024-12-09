#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

std::vector<std::vector<long>> readInput(std::string filepath) {
    std::ifstream infile(filepath.c_str());
    std::string line;
    std::vector<std::vector<long>> ret;
    long val = 0;
    while(std::getline(infile, line)) {
        std::vector<long> goods = {};
        for(long i = 0; i < line.size(); i++) {
            if(line[i] ==' ')
                goods.push_back(std::stol(line.substr(i+1, line.size()-i)));
        }
        goods.push_back(std::stol(line));
        ret.push_back(goods);
    }
    return ret;
}

long waysToCalc(long ans, std::vector<long> nums, long i, long sum){
    if(i == nums.size())
        return sum == ans;
    if(sum > ans)
        return 0;
    return waysToCalc(ans, nums, i+1, sum + nums[i]) + waysToCalc(ans, nums, i+1, sum * nums[i]);
}


bool waysToCalc2(long ans, std::vector<long> nums, long i, std::string sum){
    long s = std::stol(sum);
    if(i == nums.size())
        return s == ans;
    if(s > ans)
        return false;

    return waysToCalc2(ans, nums, i+1, std::to_string(s + nums[i])) || waysToCalc2(ans, nums, i+1, std::to_string(s * nums[i])) || waysToCalc2(ans,nums, i+1, sum +std::to_string(nums[i]));
}




int main(int argc, char* argv[]) {
    std::vector<std::vector<long>> input = readInput(argv[1]);

    long ans1 = 0;
    long ans2 = 0;

    for(auto eq : input) {
        long cal = eq[eq.size()-1];
        eq.pop_back();
        long c = waysToCalc(cal, eq, 0, 0);
        if(c > 0)
            ans1 += cal;

        if(waysToCalc2(cal, eq, 0, "0"))
            ans2+= cal;
    }


// Passed
    std::cout << "Solution 1: There are " <<ans1<<" ways to calibrate the value"<<std::endl;


// Passed
    std::cout << "Solution 2: There are "<<ans2<<" ways to block the guard."<<std::endl;

}
