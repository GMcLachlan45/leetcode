// Runtime: 4ms
// Memory: 23.5MB
class Solution {
    bool isPrefixAndSuffix(std::string str1, std::string str2) {
        if(str2.size() < str1.size())
            return false;

        for(int i = 0; i < str1.size(); i++)
            if(str1[i] != str2[i] || str1[str1.size() - 1 - i] != str2[str2.size() - 1 - i])
                return false;
        return true;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0; i < words.size(); i++)
            for(int j = i+1; j < words.size(); j++)
                ans += isPrefixAndSuffix(words[i], words[j]);
        return ans;
    }
};
