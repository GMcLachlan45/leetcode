// Runtime 40ms
// Memory 17.29MB
class Solution {
public:
    int minDeletions(string s) {
        int letter_count[26] = {};
        for(char c: s) {
            letter_count[c-'a']++;
        }
        int deletions = 0;
        std::unordered_set<int> counts;
        for(int i = 0; i<26; i++) {
            while(letter_count[i] && counts.count(letter_count[i])) {
                letter_count[i]--;
                deletions++;
            }
            if(letter_count[i])
                counts.insert(letter_count[i]);
        }
        return deletions;
    }
};
