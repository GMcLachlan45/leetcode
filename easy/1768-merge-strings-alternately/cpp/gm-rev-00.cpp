// Runtime 0ms
// Memory 6.5MB
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged(word1.size() + word2.size(), '-');
        char diff = word1.size()-word2.size();
        unsigned char len = (diff > 0) ? word2.size() : word1.size();
        for(unsigned char p = 0; p < len; p++){
            merged[2*p] = word1[p];
            merged[2*p +1] = word2[p];
        }

        if(diff == 0)
            return merged;
         merged.replace(merged.begin() + 2 * len, merged.end(), 
            (diff > 0) ? word1.substr(len, diff) : word2.substr(len, -1*diff));
        return merged;
    }
};
