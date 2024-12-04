// Runtime: 9ms
// Memory: 82.1MB
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        std::string ans(s.size() + spaces.size(), ' ');
        int s_ptr = 0;
        int space_ptr = 0;
        for(int i = 0; i < ans.size(); i++) {
            if(space_ptr < spaces.size() && s_ptr == spaces[space_ptr]) {
                i++;
                space_ptr++;
            }
            ans[i] = s[s_ptr++];
        }
        return ans;
    }
};
