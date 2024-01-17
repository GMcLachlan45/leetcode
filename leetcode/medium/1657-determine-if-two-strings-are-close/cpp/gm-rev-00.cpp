// Runtime: 92ms
// Memory: 20.95MB
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        std::vector<bool> ch1(26);
        std::vector<bool> ch2(26);
        std::vector<int> one(26);
        std::vector<int> two(26);
        for(int i = 0; i < word1.size(); i++) {
            ch1[word1[i]-'a'] = true;
            ch2[word2[i]-'a'] = true;
            one[word1[i]-'a']++;
            two[word2[i]-'a']++;
        }
        std::sort(one.begin(), one.end());
        std::sort(two.begin(), two.end());
        return ch1 == ch2 && one == two;
    }
};
