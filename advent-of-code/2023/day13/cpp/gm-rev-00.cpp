#include <string>
#include <iostream>
#include <vector>
#include "../../../bin/input-reader.cpp"
#include <stack>

std::vector<std::string> transpose(std::vector<std::string> mirror){
    int width = mirror[0].size();
    int height = mirror.size();

    std::vector<std::string> t(width);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++){
            t[j].push_back(mirror[i][j]);
        }
    }
    return t;
}


int findMirrorRow(std::vector<std::string> mirror) {
    int width = mirror[0].size();
    int height = mirror.size();
    std::stack<std::string> save;
    save.push(mirror[0]);

    std::stack<std::string> toPop;
    int mirrorPlace = -1;
    for(int i = 1; i < height; i++) {
        if((mirror[i] == save.top()) || (!toPop.empty() && mirror[i] == toPop.top())) {
            if(mirrorPlace == -1) {
                toPop = save;
                mirrorPlace = i;
            }
            toPop.pop();
            if(toPop.empty())
                break;
        } else if(mirrorPlace != -1){
            mirrorPlace = -1;
            toPop = std::stack<std::string>();
        }
        save.push(mirror[i]);
    }
    return mirrorPlace;
}

int main(int argc, char* argv[]) {
    std::vector<std::vector<std::string>> mirrors;
    std::vector<std::string> input;
    for(std::string in : readInputs(argv[1])) {
        if(in ==""){
            mirrors.push_back(input);
            input.clear();
        } else
            input.push_back(in);
    }
    mirrors.push_back(input);
    int total = 0;
    for(std::vector<std::string> mirror : mirrors) {
        for(std::string m: mirror)
            std::cout<<m<<std::endl;
        int mirrorPlace = findMirrorRow(mirror);
        if(mirrorPlace != -1) {
            std::cout<< "Added row " << 100* (mirrorPlace) <<std::endl;
            total += 100 * mirrorPlace;
            std::cout<<std::endl<<std::endl;
            continue;
        }
        std::cout<<std::endl<<"Didnt work hence"<<std::endl;
        mirrorPlace = findMirrorRow(transpose(mirror));
        if(mirrorPlace != -1) {
            std::cout<< "Added colunm " << (mirrorPlace) <<std::endl;
            total += mirrorPlace;
            std::cout<<std::endl<<std::endl;
        }

    }




    std::cout << "Solution 1: The summary of my notes is " << total <<std::endl;
    return 0;
}
