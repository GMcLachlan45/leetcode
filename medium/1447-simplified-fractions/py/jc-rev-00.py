# runtime: 150ms (100%!)
# memory: 14MB
class Solution(object):
    def simplifiedFractions(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        out = []
        dec = set()
        for i in range(2, n+1):
            for j in range(1, i):
                d = j * 1.00 / i
                if d not in dec:
                    dec.add(d)
                    out.append(str(j) + "/" + str(i))
        return out