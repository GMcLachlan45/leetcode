// Runtime: 0ms
// Memory: 8.11MB
class Solution {
public:
    int minimumPushes(string word) {
        if(word.size() < 8)
            return word.size();
        if(word.size() < 16)
            return -8 + 2 * word.size();
        if(word.size() < 24)
            return -24 + 3 * word.size();
        return -48 + 4 * word.size();
    }
};
