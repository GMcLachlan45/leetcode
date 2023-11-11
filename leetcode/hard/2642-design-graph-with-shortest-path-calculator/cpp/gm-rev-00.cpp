// Runtime: 1564ms
// Memory: 400.2MB
class Graph {
    std::vector<std::vector<std::pair<int,int>>> adjList;
public:
    Graph(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<std::pair<int,int>>> init(n);
        adjList = init;
        for(std::vector<int> edge: edges)
            addEdge(edge);
    }

    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        std::vector<int> paths(adjList.size(), -1);

        // Node to visit, current path cost
        std::queue<std::pair<int,int>> visit;
        visit.push({node1, 0});
        while(!visit.empty()) {
            int node = visit.front().first;
            int cost = visit.front().second;
            visit.pop();

            if(cost >= paths[node] && paths[node] != -1)
                continue;
            paths[node] = cost;
            for(std::pair<int,int> edge : adjList[node]){
                visit.push({edge.first, edge.second+cost});
            }
        }

        return paths[node2];
    }
};
