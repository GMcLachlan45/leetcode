#include <iostream>
#include <vector>
#include <string>

#include <stack>

class TrieNode {
public:
    TrieNode* children[128];
    TrieNode () {};
};

std::vector<std::string> autocomplete(std::string s, std::vector<std::string> possible) {
    if(s == "")
        return possible;

    TrieNode* prefixTrie = new TrieNode();;

    for(std::string word : possible) {
        TrieNode* ptr = prefixTrie;
        for(char c : word) {
            if(!ptr->children[c])
                ptr->children[c] = new TrieNode();
            ptr = ptr->children[c];
        }
        ptr->children[0] = new TrieNode();

    }


    for(char c : s) {
        if(!prefixTrie)
            break;
        prefixTrie = prefixTrie->children[c];
    }
    if(!prefixTrie)
        return {};

    //find all the possible strings
    std::vector<std::string> ans;
    std::stack<TrieNode*> prefix_st;
    std::stack<char> pointer_st;
    prefix_st.push(prefixTrie);
    pointer_st.push(0);
    pointer_st.push(127);
    while(!prefix_st.empty()) {
        if(prefix_st.top() && pointer_st.top() > 0) {
            prefix_st.push(prefix_st.top()->children[pointer_st.top()]);
            s.push_back(pointer_st.top());
            pointer_st.push(127);
            continue;
        }
        if(prefix_st.top() && prefix_st.top()->children[0])
            ans.push_back(s);
        prefix_st.pop();
        pointer_st.pop();
        pointer_st.top()--;
        s.pop_back();
    }
    return ans;
}

int main() {
    std::string query = "de";
    std::vector<std::string> possible = {"dog", "deer", "deal"};

    std::cout<< "Autocomplete results for " << query <<":"<<std::endl;
    for(std::string result : autocomplete(query, possible))
        std::cout << "    " << result<<std::endl;

    query = "d";
    possible = {"dog", "deer", "deep", "deeper"};

    std::cout<< "Autocomplete results for " << query <<":"<<std::endl;
    for(std::string result : autocomplete(query, possible))
        std::cout << "    " << result<<std::endl;

    query = "d";
    possible = {"dog", "deer", "deep", "deeper", "Do you work", "did he know that?", "???"};

    std::cout<< "Autocomplete results for " << query <<":"<<std::endl;
    for(std::string result : autocomplete(query, possible))
        std::cout << "    " << result<<std::endl;

    query = "NOT IN";
    possible = {"NO", "Nothing", "Nada"};

    std::cout<< "Autocomplete results for " << query <<":"<<std::endl;
    for(std::string result : autocomplete(query, possible))
        std::cout << "    " << result<<std::endl;

    query = "";
    possible = {"And now", "everything", "??++{+)["};

    std::cout<< "Autocomplete results for " << query <<":"<<std::endl;
    for(std::string result : autocomplete(query, possible))
        std::cout << "    " << result<<std::endl;
}
