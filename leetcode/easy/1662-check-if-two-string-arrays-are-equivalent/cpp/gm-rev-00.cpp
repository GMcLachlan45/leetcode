// Runtime: 3ms
// Memory: 11.57MB
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int ptr1 = 0;
        int wordPtr1 = 0;
        int ptr2 = 0;
        int wordPtr2 = 0;
        while(ptr1<word1.size() && ptr2<word2.size()) {
            if(word1[ptr1][wordPtr1] != word2[ptr2][wordPtr2])
                return false;
            wordPtr1++;
            wordPtr2++;
            if(wordPtr1 >= word1[ptr1].size()) {
                ptr1++;
                wordPtr1 = 0;
            }
            if(wordPtr2 >= word2[ptr2].size()) {
                ptr2++;
                wordPtr2 = 0;
            }
        }
        return ptr1 == word1.size() && ptr2 == word2.size();
    }
};
