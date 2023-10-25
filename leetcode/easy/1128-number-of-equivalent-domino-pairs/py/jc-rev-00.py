# runtime: 322ms
# memory: 25.4MB
class Solution(object):
    def numEquivDominoPairs(self, dominoes):
        """
        :type dominoes: List[List[int]]
        :rtype: int
        """
        ct = 0
        s = set([tuple(d) for d in dominoes])
        for d in s:
            dl = list(d)
            rev = dl[::-1]
            n = dominoes.count(dl)
            if d[0] != d[1]:
                n = n + dominoes.count(rev)
            if d[0] <= d[1] or d[::-1] not in s:
                ct = ct + n * (n-1) / 2
        return ct