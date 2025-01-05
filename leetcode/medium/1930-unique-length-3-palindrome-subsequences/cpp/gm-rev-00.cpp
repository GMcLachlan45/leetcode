// Runtime: 177ms
// Memory: 38.34MB
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int post_char_count[26];
        for(char c : s)
            post_char_count[c-'a']++;
        int pre_char_count[26];

        // Need to store the palindromes
        // stored as 100 * edges + middle
        std::unordered_set<int> cache;
        for(char c : s) {
            post_char_count[c-'a']--;
            for(int i = 0; i < 26; i++)
                if(pre_char_count[i] > 0 && post_char_count[i] > 0)
                    cache.insert(i*100+c);
            pre_char_count[c-'a']++;
        }
        return cache.size();
    }
};
