# runtime: 247ms
# memory: 28.8MB
class Solution(object):
    def bfs(self, grid, x, y):
        if x < 0 or y < 0 or x >= len(grid) or y >= len(grid[0]) or grid[x][y] != "1":
            return
        grid[x][y] = "2"
        self.bfs(grid,x-1,y)
        self.bfs(grid,x+1,y)
        self.bfs(grid,x,y-1)
        self.bfs(grid,x,y+1)
        
    
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    count += 1
                    self.bfs(grid, i, j)
            
        return count