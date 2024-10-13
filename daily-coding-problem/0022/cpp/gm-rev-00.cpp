#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class TrieNode {
public:
    TrieNode* children[128];
    TrieNode() {
    }
};

std::vector<std::string> helper(TrieNode* prefixTrie, std::vector<bool>* deadEnds, std::string s, int front) {
    std::vector<std::string> words = {};
    TrieNode* ptr = prefixTrie;
    int end = front;
    while(end < s.size() && ptr->children[s[end]]) {
        ptr = ptr->children[s[end++]];
        if(ptr->children['\n'] && !deadEnds->at(end)) {
            words = helper(prefixTrie, deadEnds, s, end);
            if(!words.empty() || end >= s.size()) {
                words.push_back(s.substr(front, end-front));
                break;
            } else
                (*deadEnds)[end] = true;
        }
    }
    return words;
}

std::vector<std::string> separateIntoWords(std::vector<std::string> dict, std::string s) {
    // Construct the prefix trie from the dictionary
    TrieNode* prefixTrie = new TrieNode();
    for(std::string word : dict) {
        TrieNode* ptr = prefixTrie;
        for(char c : word) {
            if(!ptr->children[c])
                ptr->children[c] = new TrieNode();
            ptr = ptr->children[c];
        }
        ptr->children['\n'] = new TrieNode();
    }

    std::vector<bool> deadEnds(s.size() + 1);

    std::vector<std::string> words = helper(prefixTrie, &deadEnds, s, 0);
    std::reverse(words.begin(), words.end());
    return words;
}

int main() {
    std::vector<std::string> dict = {"bed", "bath", "bedbath", "and", "beyond"};
    std::string s = "bedbathandbeyond";

    std::vector<std::string> ret = separateIntoWords(dict, s);

    if(ret.empty())
        std::cout << "There is no way to separate the string " << s<<std::endl;
    else {
        std::cout << "Separating the string " <<s << " results in"<<std::endl<<"[";
        for(std::string st : ret)
            std::cout<< st<<", ";
        std::cout<<"]"<<std::endl<<std::endl;
    }

    dict = {"bed", "bat", "bedbath", "and", "beyond"};
    s = "bedbathandbeyond";

    ret = separateIntoWords(dict, s);

    if(ret.empty())
        std::cout << "There is no way to separate the string " << s<<std::endl;
    else {
        std::cout << "Separating the string " <<s << " results in"<<std::endl<<"[";
        for(std::string st : ret)
            std::cout<< st<<", ";
        std::cout<<"]"<<std::endl<<std::endl;
    }

    dict = {"bed", "bat", "bedbat", "and", "beyond", "h"};
    s = "bedbathandbeyond";

    ret = separateIntoWords(dict, s);

    if(ret.empty())
        std::cout << "There is no way to separate the string " << s<<std::endl;
    else {
        std::cout << "Separating the string " <<s << " results in"<<std::endl<<"[";
        for(std::string st : ret)
            std::cout<< st<<", ";
        std::cout<<"]"<<std::endl<<std::endl;
    }

    dict = {"aa","aaaa","aaaaaa", "aaaaaaaa","aaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    ret = separateIntoWords(dict, s);

    if(ret.empty())
        std::cout << "There is no way to separate the string " << s<<std::endl;
    else {
        std::cout << "Separating the string " <<s << " results in"<<std::endl<<"[";
        for(std::string st : ret)
            std::cout<< st<<", ";
        std::cout<<"]"<<std::endl<<std::endl;
    }

}
