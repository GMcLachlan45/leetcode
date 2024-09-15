// Runtime: 37ms
// Memory: 17.7MB
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0;
        int key = 0;
        int firstInstance[32];
        std::fill_n(firstInstance, 32, -1);
        firstInstance[0] = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a')
                key ^= 1;
            else if(s[i] == 'e')
                key ^= 2;
            else if(s[i] == 'i')
                key ^= 4;
            else if(s[i] == 'o')
                key ^= 8;
            else if(s[i] == 'u')
                key ^= 16;

            if(firstInstance[key] == -1)
                firstInstance[key] = i+1;
            else if(i+1 - firstInstance[key] > ans)
                ans = i+1 - firstInstance[key];
        }

        return ans;
    }
};
