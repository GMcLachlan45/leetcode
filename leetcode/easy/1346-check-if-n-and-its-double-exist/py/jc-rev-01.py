# runtime: 31ms
# memory: 13.3MB
class Solution(object):
    def checkIfExist(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        ch = set()
        for i in arr:
            if i * 2 in ch or i / 2.00 in ch:
                return True
            ch.add(i)
        return False