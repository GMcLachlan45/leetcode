// Runtime: 7ms
// Memory: 62MB
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        char maxCount[26] = {};

        for(std::string word : words2) {
            char count[26] = {};
            for(char c : word)
                count[c-'a']++;
            for(int i = 0; i < 26; i++)
                if(count[i] > maxCount[i])
                    maxCount[i] = count[i];
        }

        std::vector<std::string> ans;

        for(std::string word : words1) {
            char count[26] = {};
            for(char c: word)
                count[c-'a']++;
            bool universal = true;
            for(int i = 0; universal && i < 26; i++)
                universal = count[i] >= maxCount[i];
            if(universal)
                ans.push_back(word);
        }
        return ans;
    }
};
