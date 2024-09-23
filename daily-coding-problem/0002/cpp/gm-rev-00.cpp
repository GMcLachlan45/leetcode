#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> productExceptIArray(std::vector<int>& arr) {
    int prod = 1;
    int zeroIdx = -1;
    std::vector<int> ret(arr.size());
    for(int i = 0; i < arr.size(); i++) {
        // If we have multiple zeros, then the entire array will be zeros
        if(zeroIdx >=0 && arr[i] == 0)
            return ret;
        // if there are <=1 zeros, then
        if(arr[i] != 0)
            prod *= arr[i];
        else
            zeroIdx = i;
    }

    // if there's only one zero then the only non zero will be at zeros index
    if(zeroIdx > -1) {
        ret[zeroIdx] = prod;
        return ret;
    }

    // if there are no zeros at all, then we do the work of getting the array
    // of product/arr[i]
    for(int i = 0; i < arr.size(); i++)
        ret[i] = prod/arr[i];
    return ret;
}

std::vector<int> productExceptIArray2(std::vector<int>& arr) {
    // no sense in going through the trouble if we'll end up with zeros everywhere
    bool foundZero = false;
    for(int num : arr) {
        if(foundZero && num == 0)
            return std::vector<int>(arr.size());
        foundZero |= num == 0;
    }

    std::vector<int> ret(arr.size(), 1);
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < i; j++)
            ret[i] *= arr[j];
        for(int j = i+1; j < arr.size(); j++)
            ret[i] *= arr[j];
    }
    return ret;
}

int main() {
    std::vector<int> nums = {1,2,3};

    std::cout << "The answer for [";
    for(int x : nums)
        std::cout<< x << "," ;
    std::cout << "] is "<<std::endl<<"[";
    for(int x : productExceptIArray2(nums))
        std::cout << x << ",";
    std::cout << "]" <<std::endl<<std::endl;;

    nums = {-2,5,-7,11};

    std::cout << "The answer for [";
    for(int x : nums)
        std::cout<< x << "," ;
    std::cout << "] is "<<std::endl<<"[";
    for(int x : productExceptIArray2(nums))
        std::cout << x << ",";
    std::cout << "]" <<std::endl<<std::endl;;

    nums = {10,15,3,7,0};
    std::cout << "The answer for [";
    for(int x : nums)
        std::cout<< x << "," ;
    std::cout << "] is "<<std::endl<<"[";
    for(int x : productExceptIArray2(nums))
        std::cout << x << ",";
    std::cout << "]" <<std::endl<<std::endl;;

    nums = {10,0,15,3,7,0};
    std::cout << "The answer for [";
    for(int x : nums)
        std::cout<< x << "," ;
    std::cout << "] is "<<std::endl<<"[";
    for(int x : productExceptIArray2(nums))
        std::cout << x << ",";
    std::cout << "]" <<std::endl<<std::endl;;

    nums = {};

    std::cout << "The answer for [";
    for(int x : nums)
        std::cout<< x << "," ;
    std::cout << "] is "<<std::endl<<"[";
    for(int x : productExceptIArray2(nums))
        std::cout << x << ",";
    std::cout << "]" <<std::endl<<std::endl;;


}
