# runtime: 15ms
# memory: 13.5MB
class Solution(object):
    def removeOuterParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        out = []
        d = 0
        for c in s:
            if (c == "(" and d > 0) or (c == ")" and d >1):
                out.append(c)
            d = d + (1 if c=="(" else -1)
        return ''.join(out)