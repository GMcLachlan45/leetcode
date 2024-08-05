// Runtime: 12ms
// Memory: 18.5MB
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        std::unordered_map<std::string, int> mp;
        for(std::string x : arr)
            mp[x]++;
        int n = 0;
        for(std::string x : arr) {
            if(mp[x] == 1)
                n++;
            if(n == k)
                return x;
        }
        return "";
    }
};
