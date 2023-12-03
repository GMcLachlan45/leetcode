#include <iostream>
#include <string>
#include <unordered_set>
#include "../../../bin/input-reader.cpp"

int main(int argc, char* argv[]) {
    std::string input = readInput(argv[1]);
    // Positions for just Santa,and Santa and Robo-Santa respectively
    int x, y, sx, sy, rx, ry = 0;
    // The houses visited when it's just Santa starting with 0,0
    std::unordered_set<std::string> st1 = {"0 0"};
    // The houses that are reached with both Santa and Robo-Santa
    std::unordered_set<std::string> st2= {"0 0"};
    for(int i = 0; i < input.size(); i++) {
        switch(input[i]) {
        case '^':
            x++;
            (i%2) ? rx++ : sx++;
            break;
        case 'v':
            x--;
            (i%2) ? rx-- : sx--;
            break;
        case '<':
            y--;
            (i%2) ? ry-- : sy--;
            break;
        case '>':
            y++;
            (i%2) ? ry++ : sy++;
            break;
        }
        st1.insert(std::to_string(x) + " " + std::to_string(y));
        st2.insert(std::to_string((i%2) ? rx: sx) + " " + std::to_string((i%2) ? ry: sy));
    }
    // Correct
    std::cout<< "Solution 1: Santa has delivered to "<< st1.size()<<" houses."<<std::endl;
    // Correct
    std::cout<< "Solution 2: Santa and Robo Santa have delivered to "<< st2.size()<<std::endl;
    return 0;
}
