// Runtime: 3ms
// Memory: 12.9MB
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        std::priority_queue<int> pq;
        for(int gift : gifts)
            pq.push(gift);
        while(k--) {
            pq.push(std::sqrt(pq.top()));
            pq.pop();
        }
        long long ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
