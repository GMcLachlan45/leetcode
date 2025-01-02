// Runtime: 0ms
// Memory: 69.2MB
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        std::vector<int> vowel_strings(words.size());
        int count = 0;
        for(int i = 0; i < words.size(); i++) {
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1]))
                count++;
            vowel_strings[i] = count;
        }

        std::vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            ans[i] = vowel_strings[queries[i][1]];
            if(queries[i][0] > 0)
                ans[i] -= vowel_strings[queries[i][0] - 1];
        }

        return ans;
    }
};
