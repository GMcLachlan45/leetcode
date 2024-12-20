// Runtime: 0ms
// Memory: 14.31MB
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        std::vector<int> answer = prices;

        std::stack<int> need_discounts;
        for(int i = 0; i < prices.size(); i++) {
            while(!need_discounts.empty() && prices[need_discounts.top()] >= prices[i]) {
                answer[need_discounts.top()] -= prices[i];
                need_discounts.pop();
            }
            need_discounts.push(i);
        }
        return answer;
    }
};
