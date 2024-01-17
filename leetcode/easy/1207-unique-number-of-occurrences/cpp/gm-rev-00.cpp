// Runtime: 0ms
// Memory: 8.9MB
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int,int> mp;
        for(int i : arr)
            mp[i]++;
        std::unordered_set<int> occurences;
        for(auto x : mp) {
            if(occurences.count(x.second))
                return false;
            occurences.insert(x.second);
        }
        return true;
    }
};
