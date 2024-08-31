// Runtime: 180ms
// Memory: 76.1MB
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        std::unordered_map<int, std::vector<std::pair<double, int>>> neighborhood(n);
        for(int i = 0; i < edges.size(); i++) {
            neighborhood[edges[i][0]].push_back({succProb[i], edges[i][1]});
            neighborhood[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        std::vector<bool> visited(n);
        std::priority_queue<std::pair<double, int>> pq;
        pq.push({1, start_node});

        double ans = 0;
        while(!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            if(current.second == end_node && current.first > ans)
                ans = current.first;
            if(visited[current.second])
                continue;
            for(auto neighbor : neighborhood[current.second])
                pq.push({current.first * neighbor.first, neighbor.second});
            visited[current.second] = true;
        }
        return ans;
    }
};
