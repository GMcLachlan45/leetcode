# runtime: 897ms
# memory: 22.8MB

class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """

        ave = sum(nums[0:k])
        val = ave
        for n in range(1, len(nums) - k + 1):
            ave = ave - nums[n-1] + nums[n+k-1]
            if ave > val:
                val = ave
        return val * 1.00 / k