// Runtime: 258ms
// Memory: 47.9
class Solution {
    std::unordered_set<std::string> have;
public:
    int maxUniqueSplit(string s) {
        if(!s.size())
            return 0;
        int maxSplits = 0;
        for(int i = 0; i < s.size(); i++) {
            if(!have.count(s.substr(0,i+1))) {
                have.insert(s.substr(0,i+1));
                int splits = 1 + maxUniqueSplit(s.substr(i+1, s.size() - i - 1));
                have.erase(s.substr(0,i+1));
                if(splits > maxSplits)
                    maxSplits = splits;
            }
        }
        return maxSplits;
    }
};
