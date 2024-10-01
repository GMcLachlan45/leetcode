#include <iostream>
#include <vector>

int largestSumOfNonAdjacent(std::vector<int> arr) {
    int iMinus2thSolution = 0;
    int iMinus1thSolution = 0;

    for(int i = 0; i < arr.size(); i++) {
        int temp = iMinus2thSolution + ((arr[i] > 0) ? arr[i] : 0);
        if(iMinus1thSolution > temp)
            temp = iMinus1thSolution;
        iMinus2thSolution = iMinus1thSolution;
        iMinus1thSolution = temp;
    }

    return (iMinus1thSolution > iMinus2thSolution) ? iMinus1thSolution : iMinus2thSolution;
}

int main() {
    std::vector<int> input = {5, 1, 1, 5};
    std::cout << "For the input " << std::endl<<"[";
    for(auto x : input)
        std::cout<< x << " ";
    std::cout<< "]"<<std::endl<< "the largest sum of non-adjacent numbers is " << largestSumOfNonAdjacent(input) << std::endl;

    input = {5,1,2,6,3,7};
    std::cout << "For the input " << std::endl<<"[";
    for(auto x : input)
        std::cout<< x << " ";
    std::cout<< "]"<<std::endl<< "the largest sum of non-adjacent numbers is " << largestSumOfNonAdjacent(input) << std::endl;


    input = {};
    std::cout << "For the input " << std::endl<<"[";
    for(auto x : input)
        std::cout<< x << " ";
    std::cout<< "]"<<std::endl<< "the largest sum of non-adjacent numbers is " << largestSumOfNonAdjacent(input) << std::endl;
}
