// Runtime: 4ms
// Memory: 20MB
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {

        if(grid.size() == 1)
            return 1 + (grid[0] ==" ");

        std::vector<std::vector<bool>> visited(grid.size()+1, std::vector<bool>(grid.size()+1));

        for(int i = 0; i < visited.size(); i++) {
            visited[0][i] = true;
            visited[i][0] = true;
            visited[visited.size()-1][i] = true;
            visited[i][visited.size()-1] = true;
        }
        visited[0][0] = true;
        visited[visited.size()-1][visited.size()-1] = true;

        int ans = 1;
        if(grid[0][0] == '/')
            ans++;
        if(grid[grid.size()-1][grid.size()-1] == '/')
            ans++;
        if(grid[0][grid.size()-1] == '\\')
            ans++;
        if(grid[grid.size()-1][0] == '\\')
            ans++;

        for(int i = 1; i < visited.size()-1; i++) {
            for(int j = 1; j < visited.size()-1; j++){
                if(visited[i][j])
                    continue;

                // Start the DFS to find loops
                std::stack<std::pair<int,int>> dfs;
                dfs.push({i,j});
                bool touchedEdge = false;
                while(!dfs.empty()) {
                    std::pair<int,int> curr = dfs.top();
                    dfs.pop();
                    // Check to see if visited
                    if(visited[curr.first][curr.second]) {
                        // If it's the edge, then we also need to have touched the edge
                        if(touchedEdge || !(curr.first == 0 || curr.first == visited.size()-1 || curr.second == 0 || curr.second == visited.size()-1)) {
                            ans++;
                        } else {
                            touchedEdge = true;
                        }
                        continue;
                    }
                    visited[curr.first][curr.second] = true;

                    // Push the edges and remove them so we don't back track
                    if(grid[curr.first-1][curr.second-1] == '\\') {
                        dfs.push({curr.first-1, curr.second-1});
                        grid[curr.first-1][curr.second-1] = ' ';
                    }
                    if(grid[curr.first-1][curr.second] == '/') {
                        dfs.push({curr.first-1, curr.second+1});
                        grid[curr.first-1][curr.second] = ' ';
                    }
                    if(grid[curr.first][curr.second-1] == '/') {
                        dfs.push({curr.first+1, curr.second-1});
                        grid[curr.first][curr.second-1] = ' ';
                    }
                    if(grid[curr.first][curr.second] == '\\') {
                        dfs.push({curr.first+1, curr.second+1});
                        grid[curr.first][curr.second] = ' ';
                    }
                }
            }
        }
        return ans;
    }
};
