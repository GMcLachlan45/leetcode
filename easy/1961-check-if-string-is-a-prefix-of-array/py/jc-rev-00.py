# runtime: 19ms
# 13.4 MB
class Solution(object):
    def isPrefixString(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: bool
        """
        st = ""
        for w in words:
            st = st + w
            if st == s:
                return True
        return False