# runtime: 51ms 
# memory: 14.4MB
class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        m = len(dungeon)        # number of rows
        n = len(dungeon[0])     # number of columns

        if m == n == 1:
            return max(-1 * dungeon[0][0], 0) + 1

        #for r in range(m):
        #    for c in range(n):
        #        dungeon[r][c] *= -1
        
        bestHP = [[0 for c in range(n)] for r in dungeon]

        bestHP[m-1][n-1] = min(dungeon[m-1][n-1], 0)

        # iterate over rightmost column and bottom row
        for r in range(m-2, -1, -1):
            bestHP[r][n-1] = min(bestHP[r+1][n-1] + dungeon[r][n-1], 0)

        for c in range(n-2, -1, -1):
            bestHP[m-1][c] = min(bestHP[m-1][c+1] + dungeon[m-1][c], 0)

        # do whole rest of table. O(m x n) time

        for r in range(m-2, -1, -1):
            for c in range(n-2, -1, -1):
                right = bestHP[r][c+1] + dungeon[r][c]
                down = bestHP[r+1][c] + dungeon[r][c]
                best = max(right, down)
                bestHP[r][c] = min(best, 0)
        return -1 * bestHP[0][0] + 1