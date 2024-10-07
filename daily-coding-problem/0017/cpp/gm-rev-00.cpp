#include <iostream>
#include <string>
#include <sstream>
#include <stack>

int longestAbsolutePathLength(std::string filesystem) {
    std::stack<int> dirLengths;
    int currentPathLength = 0;
    int longestPathLength = 0;

    std::istringstream ss(filesystem);
    std::string line;
    while(std::getline(ss, line)) {
        int level = 0;
        bool isFile = false;
        for(char c : line) {
            if(c == '\t')
                level++;
            else if(c=='.')
                isFile = true;
        }
        while(level < dirLengths.size()) {
            currentPathLength -= dirLengths.top();
            dirLengths.pop();
        }

        if(isFile) {
            if(currentPathLength + line.size()-level > longestPathLength)
                longestPathLength = currentPathLength + line.size()-level;
        } else {
            dirLengths.push(line.size()-level + 1);
            currentPathLength += dirLengths.top();
        }
    }
    return longestPathLength;
}

int main() {
    std::string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";

    std::cout <<"The longest absolute path in the filesystem represented by "<<std::endl<< input<<std::endl <<"Is "<< longestAbsolutePathLength(input) <<std::endl;

    input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";

    std::cout <<"The longest absolute path in the filesystem represented by "<<std::endl<< input<<std::endl <<"Is "<< longestAbsolutePathLength(input) <<std::endl;

        input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext\ndir2\n\tsuperlongnamethatmayaswellbethebestbutwithnofiledotexe\n\tpog\n\t\tpogg";

    std::cout <<"The longest absolute path in the filesystem represented by "<<std::endl<< input<<std::endl <<"Is "<< longestAbsolutePathLength(input) <<std::endl;
}
