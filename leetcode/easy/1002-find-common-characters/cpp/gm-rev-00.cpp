// Runtime: 6ms
// Memory: 11.3MB
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int letters[26] = {0};
        for(char x : words[0]) {
            letters[x-'a']++;
        }
        for(std::string word : words) {
            int current_letters[26] = {0};
            for(char x : word) {
                current_letters[x-'a']++;
            }
            for(int i = 0; i < 26; i++)
                letters[i] = std::min(letters[i], current_letters[i]);
        }
        std::vector<std::string> ret;
        for(int i = 0; i < 26; i++) {
            while (letters[i]){
                ret.push_back(std::string(1, 'a'+i));
                letters[i]--;
            }
        }

        return ret;
    }
};
