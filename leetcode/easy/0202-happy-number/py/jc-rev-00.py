# runtime: 15ms
# memory: 13.3MB
import math
class Solution(object):
    def happy(self, n):
        t = 0
        while n > 0:
            t = t + pow(n % 10, 2)
            n = n / 10
        return t
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        hist = [n]
        while True:
            n = self.happy(n)
            if n == 1:
                return True
            if n in hist:
                return False
            hist.append(n)
            