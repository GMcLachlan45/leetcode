# runtime: 16ms
# memory: 13.2MB
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
                arr.append(arr[(i-1)/2] + arr[(i+1)/2])
        return max(arr)