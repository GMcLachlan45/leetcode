# runtime: 13ms
# memory: 13.3MB
class Solution(object):
    def getMaximumGenerated(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return n
        arr = [0,1]
        for i in range(2,n+1):
            if i % 2 == 0:
                arr.append(arr[i/2])
            else:
                arr.append(arr[i/2] + arr[i/2+1])
        return max(arr[n/2:])