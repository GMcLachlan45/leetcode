// Runtime: 175ms
// Memory: 78.8MB
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        std::priority_queue<int> pq(nums.begin(), nums.end());
        while(k--) {
            score+= pq.top();
            pq.push(pq.top()/3 + (pq.top()%3 != 0));
            pq.pop();
        }
        return score;
    }
};
