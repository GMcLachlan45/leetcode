// Runtime: 202ms
// Memory: 208.4MB
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
        int ans = m*n;
        for(auto guard : guards) {
            grid[guard[0]][guard[1]] = -1;
            ans--;
        }
        for(auto wall : walls) {
            grid[wall[0]][wall[1]] = -1;
            ans--;
        }

        for(auto guard: guards) {
            for(int west = guard[1] - 1; west >= 0 && grid[guard[0]][west] != -1 && grid[guard[0]][west] != 1; west--) {
                if(!grid[guard[0]][west]) {
                    ans--;
                    grid[guard[0]][west] += 1;
                }
            }
            for(int east = guard[1] + 1; east < n && grid[guard[0]][east] != -1 && grid[guard[0]][east] != 1; east++) {
                if(!grid[guard[0]][east]) {
                    ans--;
                    grid[guard[0]][east] += 1;
                }
            }

            for(int north = guard[0] - 1; north >= 0 && grid[north][guard[1]] != -1 && grid[north][guard[1]] != 2; north--) {
                if(!grid[north][guard[1]]) {
                    ans--;
                    grid[north][guard[1]] += 2;
                }
            }
            for(int south = guard[0] + 1; south < m && grid[south][guard[1]] != -1 && grid[south][guard[1]] != 2; south++) {
                if(!grid[south][guard[1]]) {
                    ans--;
                    grid[south][guard[1]] += 2;
                }
            }
        }
        return ans;
    }
};
