#include <iostream>
#include <vector>

int trappedWater(std::vector<int> elevation) {
    int maxPoint = 0;
    for(int i = 0; i < elevation.size(); i++)
        if(elevation[i] >= elevation[maxPoint])
            maxPoint = i;

    int ans = 0;
    int currentMax = elevation[0];

    for(int i = 0; i < maxPoint; i++) {
        if(elevation[i] > currentMax)
            currentMax = elevation[i];
        ans += currentMax - elevation[i];
    }

    currentMax = elevation[elevation.size() - 1];
    for(int i = elevation.size() - 1; i > maxPoint; i--) {
        if(elevation[i] > currentMax)
            currentMax = elevation[i];
        ans += currentMax - elevation[i];
    }

    return ans;
}


int main() {
    std::vector<int> input = {3,0,1,5,3,5,1};
    std::cout <<  "For the given elevations, the total trapped water is " << trappedWater(input) <<std::endl;

    input = {3,0,1,3,0,5};
    std::cout <<  "For the given elevations, the total trapped water is " << trappedWater(input) <<std::endl;

    input = {2,1,2};
    std::cout <<  "For the given elevations, the total trapped water is " << trappedWater(input) <<std::endl;

}
