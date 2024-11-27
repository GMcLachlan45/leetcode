// Runtime: 85ms
// Memory: 112.8MB
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        std::vector<int> ans;

        std::vector<int> dist_to(n);
        std::vector<std::vector<int>> roads(n);
        for(int i = 0; i < n; i++) {
            dist_to[i] = i;
            roads[i].push_back(i+1);
        }
        roads[n-1].pop_back();

        for(std::vector<int> query : queries) {
            roads[query[0]].push_back(query[1]);
            std::queue<std::pair<int,int>> bfs;
            for(int road : roads[query[0]])
                bfs.push({road, dist_to[query[0]]+1});
            while(!bfs.empty()) {
                if(bfs.front().second < dist_to[bfs.front().first]) {
                    dist_to[bfs.front().first] = bfs.front().second;
                    for(int road : roads[bfs.front().first])
                        bfs.push({road, bfs.front().second + 1});
                }
                bfs.pop();
            }
            ans.push_back(dist_to[n-1]);
        }
        return ans;
    }
};
