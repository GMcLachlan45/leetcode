#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

void readInputs(std::string filepath, std::vector<std::vector<int>>* rules, std::vector<std::vector<int>>* updates) {
    std::ifstream infile(filepath.c_str());
    std::string line;
    while(infile >> line) {
        if(!line.size())
            continue;
        if(line.size() == 5)
            rules->push_back({std::stoi(line), std::stoi(line.substr(3, 2))});
        else if(line.size()){
            std::vector<int> book;
            int sc = 0;
            for(char c : line) {
                if(c == ','){
                    book.push_back(sc);
                    sc = 0;
                } else
                    sc = sc * 10 + c-'0';

            }
            book.push_back(sc);
            updates->push_back(book);
        }
    }
}

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> rules;
    std::vector<std::vector<int>> updates;
    readInputs(argv[1], &rules, &updates);

    int ans1 = 0;
    int ans2 = 0;
    std::vector<std::vector<bool>> before(100, std::vector<bool>(100, false));

    for(auto rule : rules)
        before[rule[0]][rule[1]]=true;

    for(auto update : updates) {
        std::vector<int> sorted_update(update);

        std::sort(sorted_update.begin(), sorted_update.end(), [&] (auto l, auto r) {
            return before[l][r];
        });
        bool same = true;
        for(int i = 0; same && i < update.size(); i++)
            same = update[i] == sorted_update[i];

        if(same)
            ans1 += update[update.size()/2];
        else
            ans2 += sorted_update[sorted_update.size()/2];
    }
    // Passed
    std::cout << "Solution 1: The number of correctly ordered updates is "<<ans1<<std::endl;

    // Passed
    std::cout << "Solution 2: The wrong ones when ordered correctly is  "<<ans2<<std::endl;

}
