// Runtime: 0ms
// Memory: 12.5MB
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[396];
        std::fill_n(dp, 396, 396000);
        dp[0] = 0;
        int ptr = 0;

        for(int i = 1; ptr < days.size(); i++) {
            if(days[ptr] == i) {
                dp[i] = std::min(dp[i-1] + costs[0], dp[i]);
                dp[i+6] = std::min(dp[i-1] + costs[1], dp[i+6]);
                dp[i+29] = std::min(dp[i-1] + costs[2], dp[i+29]);
                ptr++;
            } else
                dp[i] = std::min(dp[i-1], dp[i]);
        }

        for(int i = 1; i < 31; i++) {
            dp[days[days.size()-1] + i] = std::min(dp[days[days.size()-1] + i-1], dp[days[days.size()-1] + i]);
        }
        return dp[days[days.size()-1] + 30];

    }
};
