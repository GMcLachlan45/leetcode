// Runtime: 83ms
// Memory: 23.6MB
class Solution {
public:
    int minimumDeletions(string s) {
        int as_after = 0;
        for(char c : s)
            if(c == 'a')
                as_after++;
        int ans = as_after;
        int bs_before = 0;

        for(char c : s)
            if(c == 'a') {
                as_after--;
            else
                bs_before++;
            if(ans > as_after + bs_before)
                ans = as_after + bs_before;
        }
        return ans;
    }
};
