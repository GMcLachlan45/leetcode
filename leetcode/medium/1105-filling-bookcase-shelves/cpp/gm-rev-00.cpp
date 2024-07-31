// Runtime: 0ms
// Memory: 10.9MB
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        std::vector<int> dp(books.size() + 1);
        for(int frontptr = books.size()-1; frontptr >=0; frontptr--){
            dp[frontptr] = 1000000;
            int width = 0;
            int height = 0;
            for(int backptr = frontptr; backptr < books.size() && width + books[backptr][0] <= shelfWidth; backptr++) {
                width += books[backptr][0];
                height = std::max(height, books[backptr][1]);
                dp[frontptr] = std::min(height + dp[backptr + 1], dp[frontptr]);
            }
        }
        return dp[0];
    }
};
