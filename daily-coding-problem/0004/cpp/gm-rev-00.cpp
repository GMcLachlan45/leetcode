#include <iostream>
#include <vector>
#include <algorithm>

int missingInteger(std::vector<int> nums) {
    for(int i = 0; i < nums.size(); i++)
        if(nums[i] <0 || nums[i] > nums.size())
            nums[i] = 0;

    for(int i = 0; i < nums.size(); i++)
        if(nums[i] - 1 <= i || nums[nums[i]-1] == nums[i])
            nums[nums[i]-1] = nums[i];
        else {
            std::swap(nums[i], nums[nums[i]-1]);
            i--;
        }

    for(int i = 0; i < nums.size(); i++)
        if(nums[i] != i+1)
            return i+1;
    return nums.size()+1;
};

int main() {
    std::vector<int> arr = {0,1,2,3};
    std::cout<< "For the array:"<<std::endl<<"[";
    for(int x : arr) {
        std::cout<<x<<",";
    }
    std::cout<< "]"<<std::endl;
    std::cout<< "the answer is " << missingInteger(arr)<<std::endl<<std::endl;

    arr = {-1,1,-4,3};
    std::cout<< "For the array:"<<std::endl<<"[";
    for(int x : arr) {
        std::cout<<x<<",";
    }
    std::cout<< "]"<<std::endl;
    std::cout<< "the answer is " << missingInteger(arr)<<std::endl<<std::endl;

    arr = {};
    std::cout<< "For the array:"<<std::endl<<"[";
    for(int x : arr) {
        std::cout<<x<<",";
    }
    std::cout<< "]"<<std::endl;
    std::cout<< "the answer is " << missingInteger(arr)<<std::endl<<std::endl;


    arr = {5,5,5,5,5,5};
    std::cout<< "For the array:"<<std::endl<<"[";
    for(int x : arr) {
        std::cout<<x<<",";
    }
    std::cout<< "]"<<std::endl;
    std::cout<< "the answer is " << missingInteger(arr)<<std::endl<<std::endl;


    arr = {5, 1000, 2,3,4};
    std::cout<< "For the array:"<<std::endl<<"[";
    for(int x : arr) {
        std::cout<<x<<",";
    }
    std::cout<< "]"<<std::endl;
    std::cout<< "the answer is " << missingInteger(arr)<<std::endl<<std::endl;
}
