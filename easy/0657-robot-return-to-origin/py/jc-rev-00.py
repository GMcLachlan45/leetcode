# runtime: 12ms
# memory: 13.5MB
class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        y = moves.count("U") - moves.count("D")
        x = moves.count("R") - moves.count("L")
        return x == y == 0