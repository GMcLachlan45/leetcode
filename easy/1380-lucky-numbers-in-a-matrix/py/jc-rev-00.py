# runtime: 108ms
# memory: 13.5MB

class Solution(object):
    def luckyNumbers (self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """

        wid = len(matrix[0])
        colMax = [max([x[n] for x in matrix]) for n in range(wid)]

        out = []
        for r in matrix:
            x = min(r)
            if x == colMax[r.index(x)]:
                out.append(x)
                continue

        return out