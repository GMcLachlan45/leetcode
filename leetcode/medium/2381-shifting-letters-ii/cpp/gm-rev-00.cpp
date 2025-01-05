// Runtime: 52ms
// Memory:108.3MB
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        std::vector<int> changes(s.size()+1);

        for(std::vector<int> shift : shifts)
            if(shift[2]) {
                changes[shift[0]]++;
                changes[shift[1]+1]--;
            } else {
                changes[shift[0]]--;
                changes[shift[1]+1]++;
            }

        int current_change = 0;
        for(int i = 0; i < s.size(); i++) {
            current_change += changes[i] + 130000;
            current_change %= 26;

            s[i] = (s[i]-'a' + current_change)%26 + 'a';
        }
        return s;
    }
};
