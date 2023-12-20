// Runtime: 11ms
// Memory: 46.9MB
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        std::sort(prices.begin(), prices.end());
        return (money - prices[0]-prices[1]>= 0) ? money - prices[0]-prices[1] : money;
    }
};
