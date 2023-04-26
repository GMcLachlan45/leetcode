// Runtime 4ms
// Memory 8MB
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        std::vector<int> row_count(m, 0);
        std::vector<int> col_count(n, 0);

        for(std::vector<int> x: indices) {
            row_count[x[0]]++;
            col_count[x[1]]++;
        }

        int row_odds = 0;
        for(int x: row_count)
            row_odds += x%2;

        int odd_count = 0;
        for(int x: col_count)
            odd_count += (x % 2) ? m - row_odds : row_odds;
        return odd_count;
    }
};
