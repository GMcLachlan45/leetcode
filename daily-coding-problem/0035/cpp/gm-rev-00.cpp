#include <iostream>
#include <vector>

void swap(std::vector<char>* arr, int i, int j) {
    int temp = arr->at(i);
    (*arr)[i] = arr->at(j);
    (*arr)[j] = temp;
}

void sortRGB(std::vector<char>* arr) {
    int rCount= 0;
    int gCount= 0;
    int bCount= 0;
    for(char c : *arr)
        if(c=='R')
            rCount++;
        else if (c=='G')
            gCount++;
        else
            bCount++;

    int rPtr = 0;
    int gPtr = rCount;
    int bPtr = rCount+gCount;

    int state = 0;
    while(rPtr < rCount || gPtr < rCount + gCount || bPtr < arr->size()) {
        if(arr->at(rPtr) == 'G' && arr->at(gPtr) == 'B' && arr->at(bPtr) == 'R') {
            swap(arr, rPtr, gPtr++);
            swap(arr, rPtr++, bPtr++);
        }
        if(arr->at(rPtr) == 'B' && arr->at(bPtr) == 'G' && arr->at(gPtr) == 'R') {
            swap(arr, rPtr, bPtr++);
            swap(arr, rPtr++, gPtr++);
        }

        if(state == 0) {
            if(rPtr >= rCount){
                state = 1;
                continue;
            }
            if(arr->at(rPtr) == 'R') {
                rPtr++;
            } else if(arr->at(rPtr) == 'G') {
                if(arr->at(gPtr) == 'R') {
                    swap(arr, rPtr, gPtr);
                    rPtr++;
                    gPtr++;
                } else
                    state = 1;
            } else {
                if(arr->at(bPtr) == 'B') {
                    swap(arr, rPtr, bPtr);
                    rPtr++;
                    bPtr++;
                } else
                    state = 2;
            }
        } else if(state == 1) {
            if(gPtr >= rCount + gCount){
                state = 2;
                continue;
            }
            if(arr->at(gPtr) == 'G') {
                gPtr++;
            } else if(arr->at(gPtr) == 'B') {
                if(arr->at(bPtr) == 'G') {
                    swap(arr, gPtr, bPtr);
                    gPtr++;
                    bPtr++;
                } else
                    state = 2;
            } else {
                if(arr->at(rPtr) == 'G') {
                    swap(arr, rPtr, bPtr);
                    rPtr++;
                    gPtr++;
                } else
                    state = 0;
            }
        } else if(state == 2){
            if(bPtr >= arr->size()){
                state = 0;
                continue;
            }
            if(arr->at(bPtr) == 'B') {
                bPtr++;
            } else if(arr->at(bPtr) == 'G') {
                if(arr->at(gPtr) == 'B') {
                    swap(arr, gPtr, bPtr);
                    gPtr++;
                    bPtr++;
                } else
                    state = 1;
            } else {
                if(arr->at(rPtr) == 'B') {
                    swap(arr, rPtr, bPtr);
                    rPtr++;
                    bPtr++;
                } else
                    state = 0;
            }
        }
    }
}

#include <bits/stdc++.h>
int main() {
    std::vector<char> input = {'G','B','R','R','B','R','G'};

    std::cout << "Before: " << std::endl;
    for(char x : input)
        std::cout << x << " ";
    sortRGB(&input);
    std::cout << std::endl << "After:" << std::endl;
    for(char x : input)
        std::cout << x << " ";
    std::cout << std::endl;

    input = {'G','B','G','B','R','G','B','G','B','B','G','B','G','B','R','G','B','R','G','B','G','B','R','G','B','B','G','B','R','G','B','R','G','B','B','B','R','G','B','B','G','B','B','B','G','B','R','G','B','B','R','G','B','B','G','B','B','B','G','B','R','G','B','B','B','G','B','G','B','R','G','B','B','R','G','B','R','G','B','B','G','B','R','G','B','G','B','B','R','G','B','G','B','B','B','R','G','B','G','B','B','R','G','B','B','B','R','G','B','B','R','G','B','B','B','R','G','B','R','G','B','R','G','B','B','R','G','B','G','B','G','B','G','B','R','G','B','B','G','B','G','B','R','G','B','B','B','R','G','B','R','G','B','G','B','R','G','B','B','B','G','B','G','B','R','G','B','G','B','B','G','B','G','B','B','R','G','B','G','B','B','B','G','B','B','B','G','B','G','B','G','B'};

    std::cout << "Before: " << std::endl;
    for(char x : input)
        std::cout << x << " ";
    sortRGB(&input);
    std::cout << std::endl << "After:" << std::endl;
    for(char x : input)
        std::cout << x << " ";
    std::cout << std::endl;

    input = {'G'};
    std::cout << "Before: " << std::endl;
    for(char x : input)
        std::cout << x << " ";
    sortRGB(&input);
    std::cout << std::endl << "After:" << std::endl;
    for(char x : input)
        std::cout << x << " ";
    std::cout << std::endl;


    input = {'R'};
    std::cout << "Before: " << std::endl;
    for(char x : input)
        std::cout << x << " ";
    sortRGB(&input);
    std::cout << std::endl << "After:" << std::endl;
    for(char x : input)
        std::cout << x << " ";
    std::cout << std::endl;

    input = {'B'};
    std::cout << "Before: " << std::endl;
    for(char x : input)
        std::cout << x << " ";
    sortRGB(&input);
    std::cout << std::endl << "After:" << std::endl;
    for(char x : input)
        std::cout << x << " ";
    std::cout << std::endl;

    input = {};
    std::cout << "Before: " << std::endl;
    for(char x : input)
        std::cout << x << " ";
    sortRGB(&input);
    std::cout << std::endl << "After:" << std::endl;
    for(char x : input)
        std::cout << x << " ";
    std::cout << std::endl;
}
