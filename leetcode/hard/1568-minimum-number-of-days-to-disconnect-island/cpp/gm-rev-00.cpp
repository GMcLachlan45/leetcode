// Runtime: 21ms
// Memory: 20.8MB
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int totalLand = 0;

        std::pair<int,int> firstLand;
        int ocean[32][32];
        // Put the island into an ocean
        for(int i = 0; i < grid.size(); i++ ) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]){
                    if(!totalLand)
                        firstLand = {i+1, j+1};
                    ocean[i+1][j+1] = 2;
                    totalLand++;
                }
            }
        }
        // Check for edge cases
        if(totalLand == 0)
            return 0;
        if(totalLand == 1)
            return 1;

        // First, check for cut edges by dfs'ing the ocean and looking for where
        std::stack<std::pair<int,int>> dfs;

        dfs.push({0,0});

        while(!dfs.empty()) {
            std::pair<int,int> curr = dfs.top();
            dfs.pop();
            if(curr.first < 0 || curr.first > 31 || curr.second < 0 || curr.second > 31 || ocean[curr.first][curr.second])
                continue;
            ocean[curr.first][curr.second]--;
            dfs.push({curr.first-1, curr.second});
            dfs.push({curr.first+1, curr.second});
            dfs.push({curr.first, curr.second-1});
            dfs.push({curr.first, curr.second+1});
            dfs.push({curr.first-1, curr.second-1});
            dfs.push({curr.first+1, curr.second-1});
            dfs.push({curr.first+1, curr.second-1});
            dfs.push({curr.first-1, curr.second+1});
        }

        // Next, check the land via dfs to see if its even connected
        dfs.push(firstLand);

        int minConnectedness = 4;
        int landVisited = 0;
        bool cutVertexExists = false;
        while(!dfs.empty()) {
            std::pair<int,int> curr = dfs.top();
            dfs.pop();
            if(ocean[curr.first][curr.second] != 2)
                continue;
            ocean[curr.first][curr.second] = 1;
            landVisited++;

            int edges = 0;
            if(ocean[curr.first-1][curr.second] > 0) {
                edges++;
                dfs.push({curr.first-1, curr.second});
            }
            if(ocean[curr.first+1][curr.second] > 0) {
                edges++;
                dfs.push({curr.first+1, curr.second});
            }
            if(ocean[curr.first][curr.second-1] > 0) {
                edges++;
                dfs.push({curr.first, curr.second - 1});
            }
            if(ocean[curr.first][curr.second+1] > 0) {
                edges++;
                dfs.push({curr.first, curr.second + 1});
            }

            // Check to see if its a cut vertex
            switch(edges) {
            case 2:
                cutVertexExists = cutVertexExists
                    || (ocean[curr.first-1][curr.second] == -1 && ocean[curr.first+1][curr.second] == -1)
                    || (ocean[curr.first][curr.second-1] == -1 && ocean[curr.first][curr.second+1] == -1);
                break;
            default:
            cutVertexExists = cutVertexExists
                || (ocean[curr.first-1][curr.second-1] == -1 && ocean[curr.first+1][curr.second+1] == -1)
                || (ocean[curr.first+1][curr.second-1] == -1 && ocean[curr.first-1][curr.second+1] == -1);
            }
            if(edges < minConnectedness)
                minConnectedness = edges;
        }

        // If we didn't reach every one, we're already disconnected
        if(totalLand != landVisited)
            return 0;

        // Edge case of a 2 tile island
        if(totalLand == 2)
            return 2;
        // Check if we can only remove 1
        if(cutVertexExists)
            return 1;
        // Otherwise return min edges
        return minConnectedness;
    }
};
