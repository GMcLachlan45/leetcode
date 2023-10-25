# runtime: 18ms
# memory: 13.5MB
class Solution(object):
    def secondHighest(self, s):
        """
        :type s: str
        :rtype: int
        """
        try:
            std = sorted(set(s))
            return ord(''.join(c for c in std if c.isdigit())[-2]) - 48
        except:
            return -1