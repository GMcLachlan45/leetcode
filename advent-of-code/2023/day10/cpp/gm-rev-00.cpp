#include <string>
#include <iostream>
#include <vector>
#include "../../../bin/input-reader.cpp"

int findDirection(char pipe, int currentDirection) {
    switch(pipe) {
    case '7':
        return (currentDirection == 0)? 3 : 2;
    case 'F':
        return (currentDirection == 0)? 1 : 2;
    case 'J':
        return (currentDirection == 2)? 3 : 0;
    case 'L':
        return (currentDirection == 2)? 1 : 0;
    default:
        return currentDirection;
    }
}

bool incompatible(char pipe, int direction) {
    switch(pipe) {
    case '-':
        return direction == 0 || direction == 2;
    case '|':
        return direction == 1 || direction == 3;
    case '7':
        return direction == 2 || direction == 3;
    case 'F':
        return direction == 2 || direction == 1;
    case 'J':
        return direction == 3 || direction == 0;
    case 'L':
        return direction == 1 || direction == 0;
    }
    return true;
}

int main(int argc, char* argv[]) {

    std::vector<std::string> map = readInputs(argv[1]);
    int x = map[0].size();
    int y = map.size();
    int sX = -1;
    int sY = -1;

    for(int i = 0; sX==-1 && i < y; i++) {
        for(int j = 0; j<x; j++) {
            if(map[i][j] == 'S') {
                sX = j;
                sY = i;
                break;
            }
        }
    }

    // {dead, x, y, direction} where direction 0 = n, 1 = e, 2 = s, 3 = w
    int ptrs[][4] = {{0,sX,sY,0}, {0,sX,sY,1}, {0,sX,sY,2}, {0,sX,sY,3}};
    int step = 0;
    bool end = false;
    std::vector<std::vector<char>> simp(y, std::vector<char>(x, '.'));
    while(!end) {
        for(int i = 0; i <4; i++) {
            if(ptrs[i][0])
                continue;
            switch(ptrs[i][3]){
            case 0:
                ptrs[i][2]--;
                if(ptrs[i][2] < 0 || incompatible(map[ptrs[i][2]][ptrs[i][1]],ptrs[i][3])) {
                    ptrs[i][0] = 1;
                    ptrs[i][2]++;
                }
                ptrs[i][3] = findDirection(map[ptrs[i][2]][ptrs[i][1]], ptrs[i][3]);
                break;
            case 1:
                ptrs[i][1]++;
                if(ptrs[i][2] >= x || incompatible(map[ptrs[i][2]][ptrs[i][1]],ptrs[i][3])) {
                    ptrs[i][0] = 1;
                    ptrs[i][1]--;
                }
                ptrs[i][3] = findDirection(map[ptrs[i][2]][ptrs[i][1]], ptrs[i][3]);
                break;
            case 2:
                ptrs[i][2]++;
                if(ptrs[i][2] >= y || incompatible(map[ptrs[i][2]][ptrs[i][1]],ptrs[i][3])) {
                    ptrs[i][0] = 1;
                    ptrs[i][2]--;
                }
                ptrs[i][3] = findDirection(map[ptrs[i][2]][ptrs[i][1]], ptrs[i][3]);
                break;
            case 3:
                ptrs[i][1]--;
                if(ptrs[i][2] <0 || incompatible(map[ptrs[i][2]][ptrs[i][1]],ptrs[i][3])) {
                    ptrs[i][0] = 1;
                    ptrs[i][1]++;
                }
                ptrs[i][3] = findDirection(map[ptrs[i][2]][ptrs[i][1]], ptrs[i][3]);
                break;
            }
            simp[ptrs[i][2]][ptrs[i][1]] =map[ptrs[i][2]][ptrs[i][1]];

        }
        step++;
        if(!ptrs[0][0]) {
            end = end | (ptrs[0][1] == ptrs[1][1] && ptrs[0][2] == ptrs[1][2]);
            end = end | (ptrs[0][1] == ptrs[2][1] && ptrs[0][2] == ptrs[2][2]);
            end = end | (ptrs[0][1] == ptrs[3][1] && ptrs[0][2] == ptrs[3][2]);
        }
        if(!ptrs[1][0]) {
            end = end | (ptrs[1][1] == ptrs[2][1] && ptrs[1][2] == ptrs[2][2]);
            end = end | (ptrs[1][1] == ptrs[3][1] && ptrs[1][2] == ptrs[3][2]);
        }
        if(!ptrs[2][0]) {
            end = end | (ptrs[2][1] == ptrs[3][1] && ptrs[2][2] == ptrs[3][2]);
        }

    }

    if(ptrs[0][0] == 0) {
        if(ptrs[1][0] == 0)
            simp[sY][sX] = 'L';
        else if(ptrs[2][0] == 0)
            simp[sY][sX] = '|';
        else if(ptrs[3][0] == 0)
            simp[sY][sX] = 'J';
    } else if(ptrs[1][0] == 0) {
        if(ptrs[2][0] == 0)
            simp[sY][sX] = 'F';
        else if(ptrs[3][0] == 0)
            simp[sY][sX] = '-';
    } else
        simp[sY][sX] = '7';

    int insideCount = 0;
    char state = 0;
    for(int i = 0; i < y; i++) {
        int pipesPassed = 0;
        for(int j = 0; j<x; j++ ) {
            switch(simp[i][j]) {
            case '|':
                pipesPassed++;
            case '-':
                break;
            case 'L':
                state = 'L';
                break;
            case 'F':
                state = 'F';
                break;
            case 'J':
                pipesPassed+= (state == 'F');
                state = 0;
                break;
            case '7':
                pipesPassed+= (state == 'L');
                state = 0;
                break;
            default:
                insideCount+=pipesPassed%2;
            }
        }
    }
    std::cout<< "Solution 1: the furthest point in the loop from the animal is " <<  step <<std::endl;
    std::cout<< "Solution 2: the number of tiles within the loop is "<<  insideCount <<std::endl;

    return 0;

}
