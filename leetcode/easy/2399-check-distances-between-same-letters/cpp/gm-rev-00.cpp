// Runtime 4ms
// Memory 23.2MB
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> first_idx(26, -1);
        for(int i = 0; i < s.size(); i++){
            if(first_idx[s[i]-'a'] >= 0 && i - first_idx[s[i] - 'a'] - 1 != distance[s[i] - 'a'])
                return false;
            else 
                first_idx[s[i]-'a'] = i;
        }
        return true;
    }
};
