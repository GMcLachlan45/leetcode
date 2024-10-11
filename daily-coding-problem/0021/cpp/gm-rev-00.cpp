#include <iostream>
#include <vector>
#include <algorithm>
int requiredNumberOfRooms(std::vector<std::vector<int>> intervals) {
    std::sort(intervals.begin(), intervals.end(), [] (auto l, auto r) {
        return l[0] < r[0];
    });
    std::vector<int> classEndTime;
    for(std::vector<int> interval : intervals) {
    int classNum = 0;
    while(classNum < classEndTime.size() && classEndTime[classNum] > interval[0])
            classNum++;
        if(classNum == classEndTime.size())
            classEndTime.push_back(interval[1]);
        else
            classEndTime[classNum] = interval[1];
    }
    return classEndTime.size();
}

int main() {
    std::vector<std::vector<int>> input = {};
    std::cout << "The required number of classrooms for the given intervals is " << requiredNumberOfRooms(input)<<std::endl;

    input = {{0,10}};
    std::cout << "The required number of classrooms for the given intervals is " << requiredNumberOfRooms(input)<<std::endl;

    input = {{0,10},{10,20}};
    std::cout << "The required number of classrooms for the given intervals is " << requiredNumberOfRooms(input)<<std::endl;

    input = {{3,10},{0,10}, {10,20}, {10,25}};
    std::cout << "The required number of classrooms for the given intervals is " << requiredNumberOfRooms(input)<<std::endl;

    input = {{1, 2}, {1, 2}, {1, 2}, {1, 2}, {1, 2}};
    std::cout << "The required number of classrooms for the given intervals is " << requiredNumberOfRooms(input)<<std::endl;

}
