# runtime: 32ms
# memory: 13.8MB
class Solution(object):
    def checkIfExist(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        ev = [a for a in arr if a % 2 == 0]
        for i in arr:
            if 2 * i in ev:
                if i != 0:
                    return True
                else:
                    if ev.count(0) > 1:
                        return True
        return False