// Runtime: 0ms
// Memory: 9MB
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        std::unordered_map<std::string,int> candidates;

        int word_begin = 0;
        int word_end = 0;
        while(word_begin < s1.size()) {
            while(++word_end <s1.size() && s1[word_end] != ' ');
            candidates[s1.substr(word_begin, word_end-word_begin)]++;
            word_begin = ++word_end;
        }
        word_begin = 0;
        word_end = 0;
        while(word_begin < s2.size()) {
            while(++word_end < s2.size() && s2[word_end] != ' ');
            candidates[s2.substr(word_begin, word_end-word_begin)]++;
            word_begin = ++word_end;
        }

        std::vector<std::string> ans;
        for(auto x : candidates)
            if(x.second == 1)
                ans.push_back(x.first);

        return ans;
    }
};
