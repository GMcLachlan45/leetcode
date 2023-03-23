// Runtime 42ms
// Memory 12.6MB
// Editorial Help
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        dist[src] = 0;

        for(int i = 0; i <= k; i++) {
            vector<int> next_dist(dist);
            for(auto& flight: flights) {
                if(dist[flight[0]] != std::numeric_limits<int>::max()) {
                    next_dist[flight[1]] = std::min(next_dist[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            dist = next_dist;
        }
        return (dist[dst] == std::numeric_limits<int>::max()) ? -1 : dist[dst];
    }
};