#include <iostream>
#include <vector>
#include <unordered_set>

bool twoNumbersCanAddToK(std::vector<int>& nums, int k) {
    std::unordered_set<int> needs;

    for(int num : nums) {
        if(needs.count(num))
            return true;
        needs.insert(k-num);
    }

    return false;
}

int main() {
    std::vector<int> nums = {10,15,3,7};
    int k = 17;

    std::cout << "The answer for ["<< nums[0];
    for(int x : nums)
        std::cout << ", " << x;
    std::cout << "], k = "<< k <<" is "<< twoNumbersCanAddToK(nums, k) << std::endl;


    nums = {10,15,3,7,24};
    k = 700;

    std::cout << "The answer for ["<< nums[0];
    for(int x : nums)
        std::cout << ", " << x;
    std::cout << "], k = "<< k <<" is "<< twoNumbersCanAddToK(nums, k) << std::endl;
}
