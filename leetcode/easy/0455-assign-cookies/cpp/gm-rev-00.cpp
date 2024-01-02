// Runtime: 27ms
// Memory 17.77MB
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        while(i < g.size() && j < s.size()) {
            if(g[i] <= s[j])
                i++;
            j++;
        }
        return i;
    }
};
