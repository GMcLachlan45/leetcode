// Runtime: 0ms
// Memory: 8.6MB
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        std::stringstream ss1(sentence1);
        std::stringstream ss2(sentence2);
        std::string word1;
        std::string word2;

        std::stack<std::string> st1;
        std::stack<std::string> st2;

        while(ss1 >> word1 && ss2 >> word2) {
            if(word1 != word2){
                st1.push(word1);
                st2.push(word2);
                break;
            }
        }

        while(ss1 >> word1)
            st1.push(word1);
        while(ss2 >> word2)
            st2.push(word2);

        while(!st1.empty() && !st2.empty()) {
            if(st1.top() != st2.top())
                return false;
            st1.pop();
            st2.pop();
        }

        if(st1.empty() || st2.empty())
            return true;
        return false;
    }
};
