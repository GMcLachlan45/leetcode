// Runtime: 42ms
// Memory: 18.01MB
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int numberOfChars[26] = {0};
        for(char c: chars)
            numberOfChars[c-'a']++;
        int spellableWords = 0;
        for(std::string word: words){
            int wordChars[26] = {0};
            bool canSpell = true;
            for(char c: word) {
                wordChars[c-'a']++;
                if(wordChars[c-'a']>numberOfChars[c-'a']){
                    canSpell = false;
                    break;
                }
            }
            if(canSpell)
                spellableWords+=word.size();
        }
        return spellableWords;
    }
};
