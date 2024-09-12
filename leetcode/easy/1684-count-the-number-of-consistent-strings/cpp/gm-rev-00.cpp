// Runtime: 45ms
// Memory: 33.91MB
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allowed_chars[26];
        for(char c : allowed) 
            allowed_chars[c-'a'] = true;
        int ans = words.size();
        for(std::string word : words) {
            for(char c: word)
                if(!allowed_chars[c-'a']) {
                    ans--;
                    break;
                }
        }
        return ans;
    }
};
