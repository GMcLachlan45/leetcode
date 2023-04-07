# runtime: 44ms
# memory: 13.9MB
class Solution(object):
    def checkStraightLine(self, coordinates):
        """
        :type coordinates: List[List[int]]
        :rtype: bool
        """
        (x1, y1),(x2,y2) = coordinates[0],coordinates[1]
        for x,y in coordinates[2:]:
            if (y2 - y1) * (x - x1) != (y - y1) * (x2 - x1):
                return False
        return True