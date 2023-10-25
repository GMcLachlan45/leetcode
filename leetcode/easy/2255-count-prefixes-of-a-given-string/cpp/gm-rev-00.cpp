// Runtime 10ms
// Memory 11.9MB
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;

        for(string word: words) {
            if(word.size() > s.size())
                continue;
            for(int i = 0; i < word.size(); i++) {
                if(word[i] != s[i])
                    break;
                else if(i == word.size() - 1){
                    count++;
                }
            }
        }
        return count;
    }
};
