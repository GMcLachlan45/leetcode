# runtime: 189ms
# memory: 25.4MB
class Solution(object):
    def numEquivDominoPairs(self, dominoes):
        """
        :type dominoes: List[List[int]]
        :rtype: int
        """
        diction = {}
        for d in dominoes:
            f = d[0]
            s = d[1]
            dom = 10 * min(f,s) + max(f,s)
            v = diction.get(dom, 0)
            diction.update({dom:v+1})
        
        ct = 0
        for d in diction.keys():
            n = diction.get(d)
            ct = ct + n * (n-1) / 2
        return ct