# runtime: 751ms
# memory: 21.9MB
class Solution(object):
    def maxMatrixSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        negCount = 0
        tot = 0
        mini = 100000
        for r in matrix:
            pos = [abs(n) for n in r]
            negCount += len([n for n in r if n < 0])
            if min(pos) < mini:
                mini = min(pos)
            tot += sum(pos)

        if negCount % 2 == 0:
            return tot
        return tot - 2*mini
        