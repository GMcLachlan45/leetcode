// Runtime: 50ms
// Memory: 16.88MB
class Solution {
public:
    int minSteps(string s, string t) {
        int count[128] = {0};
        for(char c : t)
            count[c]++;
        for(char c: s)
            count[c]--;

        int changes = 0;
        for(int i = 'a'; i <= 'z'; i++)
            changes += std::abs(count[i]);
        return changes/2;
    }
};
