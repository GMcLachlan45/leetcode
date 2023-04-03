import numpy as np
class Solution(object):
    def maxSumRangeQuery(self, nums, requests):
        """
        :type nums: List[int]
        :type requests: List[List[int]]
        :rtype: int
        """

        st = sorted(nums)
        counts = np.zeros(len(nums), dtype=int)
        for rq in requests:
            for i in range(rq[0], rq[1]+1):
                counts[i] = counts[i] + 1
        
        indices = np.argsort(counts)

        t = 0
        N = int(1e9)+7
        for i in range(len(indices)):
            t = (t + (counts[indices[i]] * st[i])%N) % N
        return t % N