// Runtime: 19ms
// Memory: 20.67MB
class Solution {
public:
    string compressedString(string word) {
        std::string comp;
        int c = 1;
        for(int i = 1; i < word.size(); i++) {
            if(word[i] != word[i-1] || c == 9) {
                comp.push_back((char) ('0' + c));
                comp.push_back(word[i-1]);
                c = 0;
            }
            c++;
        }
        comp.push_back((char) ('0' + c));
        comp.push_back(word[word.size() - 1]);
        return comp;
    }
};
