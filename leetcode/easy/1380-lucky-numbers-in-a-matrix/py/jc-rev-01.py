# runtime: 79ms (100%!)
# memory: 13.7MB
class Solution(object):
    def luckyNumbers (self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        transp = list(zip(*matrix))

        maxes = [max(c) for c in transp]
        mins = [min(r) for r in matrix]

        out = [x for x in maxes if x in mins]
        return out