// Runtime 123ms
// Memory: 80.1MB
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Create a vector of indices to the projects
        std::vector<int> indices(profits.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(), [&] (int l, int r) {
            return capital[l] < capital[r];
        });


        int ptr = 0;
        // Create a priority queue to get the max profits
        std::priority_queue<int> pq;

        for(int i = 0; i < k; i++) {
            while(ptr < indices.size() && capital[indices[ptr]] <= w) {
                pq.push(profits[indices[ptr++]]);
            }
            if(pq.empty())
                return w;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
