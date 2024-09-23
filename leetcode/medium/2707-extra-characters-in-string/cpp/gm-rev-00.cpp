class Solution {
public:
    int minExtraChar(string s, vector<string> dictionary) {
        int dp[52];
        std::fill_n(dp+1, 50, 50);

        std::unordered_set<int> lengths[26];
        std::unordered_set<std::string> dict;
        for(std::string word: dictionary) {
            dict.insert(word);
            lengths[word[0]-'a'].insert(word.size());
        }

        for(int i = 0; i < s.size(); i++) {
            if(dp[i+1] > dp[i] + 1)
                dp[i+1] = dp[i] + 1;
            for(int length : lengths[s[i]-'a'])
                if(i + length <= s.size() && dp[i+length] > dp[i] && dict.count(s.substr(i, length)))
                    dp[i+length] = dp[i];
        }
        return dp[s.size()];
    }
};
