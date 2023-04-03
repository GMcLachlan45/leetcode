import numpy as np
class Solution(object):
    def maxSumRangeQuery(self, nums, requests):
        """
        :type nums: List[int]
        :type requests: List[List[int]]
        :rtype: int
        """
        n = len(nums)
        st = sorted(nums)
        counts = np.zeros(len(nums), dtype=int)
        for rq in requests:
            counts[rq[0]] += 1
            if rq[1] < n-1:
                counts[rq[1]+1] -= 1
        for i in range(n):
            if i == 0:
                continue
            counts[i] += counts[i-1]
        
        indices = np.argsort(counts)

        t = 0
        N = int(1e9)+7
        for i in range(len(indices)):
            t = (t + (counts[indices[i]] * st[i])%N) % N
        return t % N