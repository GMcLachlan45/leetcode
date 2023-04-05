// Runtime 6ms
// Memory 13.8MB
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int sPtr = 0;
        int wordPtr = 0;
        int word = 0;
        while(sPtr < s.size()) {
            if(wordPtr >= words[word].size()) {
                word++;
                wordPtr = 0;
                if(word >= words.size())
                    return false;
            }
            if(s[sPtr] != words[word][wordPtr])
                return false;
            sPtr++;
            wordPtr++;
        }
        return wordPtr == words[word].size();
    }
};
