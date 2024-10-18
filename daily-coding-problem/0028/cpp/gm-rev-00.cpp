#include <iostream>
#include <vector>
#include <string>
#include <utility>

std::vector<std::string> justifiedText(std::vector<std::string> words, int k) {
    std::vector<std::string> ans;

    int line_first_word = 0;
    int i = 0;
    while(i < words.size()) {
        int space_left = k;
        int spaces_in_line = 0;
        while(i < words.size() && space_left) {
            if(words[i].size() > space_left) {
                spaces_in_line += space_left;
                break;
            }
            space_left -= words[i++].size();
            if(space_left) {
                space_left--;
                spaces_in_line++;
            }
        }
        if(i >= words.size())
            spaces_in_line += space_left;
        std::string line = "";

        while(line_first_word < i) {
            line += words[line_first_word++];
            if(i> line_first_word) {
                line += std::string(spaces_in_line / (i - line_first_word) + (spaces_in_line % (i-line_first_word) > 0) , ' ');
                spaces_in_line -= spaces_in_line / (i - line_first_word) + (spaces_in_line % (i-line_first_word) > 0);
            } else if(spaces_in_line)
                line += std::string(spaces_in_line, ' ');
        }
        ans.push_back(line);
    }
    return ans;
}

int main() {
    std::vector<std::string> words = {"the","quick","brown","fox","jumps","over","the","lazy","dog","champ"};
    int k = 16;

    std::cout << "The justified text for the given words with k=" << k << " is" <<std::endl << std::string(k, '*') <<std::endl;
    for(std::string line : justifiedText(words, k))
        std::cout<< line<<std::endl;

    words = {"the","dog","cha", "a","B"};
    k = 11;

    std::cout << "The justified text for the given words with k=" << k << " is" <<std::endl << std::string(k, '*') <<std::endl;
    for(std::string line : justifiedText(words, k))
        std::cout<< line<<std::endl;

    words = {"the","dog","cha", "a","B"};
    k = 3;

    std::cout << "The justified text for the given words with k=" << k << " is" <<std::endl << std::string(k, '*') <<std::endl;
    for(std::string line : justifiedText(words, k))
        std::cout<< line<<std::endl;
}
