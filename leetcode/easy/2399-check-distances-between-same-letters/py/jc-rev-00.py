# runtime: 21ms
# memory: 13.4MB
class Solution(object):
    def checkDistances(self, s, distance):
        """
        :type s: str
        :type distance: List[int]
        :rtype: bool
        """
        st = ''.join(set(s))

        for c in st:
            ind = ord(c) - 97
            d = s.rfind(c) - s.find(c) - 1
            if distance[ind] != d and d >= 0:
                return False
        return True

