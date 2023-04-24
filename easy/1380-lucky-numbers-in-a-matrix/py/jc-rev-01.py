# runtime: 93ms
# memory: 13.8MB
class Solution(object):
    def luckyNumbers (self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        transp = list(zip(*matrix))

        maxes = [max(c) for c in transp]
        mins = [min(r) for r in matrix]


        return [x for x in maxes if x in mins]