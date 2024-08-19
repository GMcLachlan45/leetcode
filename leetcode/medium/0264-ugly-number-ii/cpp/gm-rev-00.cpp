// Runtime: 86ms
// Memory: 39.6MB
class Solution {
public:
    int nthUglyNumber(int n) {
        std::unordered_map<long, bool> pushed;
        std::priority_queue<long, std::vector<long>, std::greater<long>> pq;
        pq.push(1);
        long ugly = 0;
        while(n > 0) {
            ugly = pq.top();
            pq.pop();
            if(!pushed[ugly*2]) {
                pushed[ugly*2] = true;
                pq.push(ugly*2);
            }
            if(!pushed[ugly*3]) {
                pushed[ugly*3] = true;
                pq.push(ugly*3);
            }
            if(!pushed[ugly*5]) {
                pushed[ugly*5] = true;
                pq.push(ugly*5);
            }
            n--;
        }
        return ugly;
    }
};
