# runtime: 914ms
# memory: 22.8MB
class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """

        val = min(nums) * k
        ave = sum(nums[0:k])
        for n in range(len(nums) - k + 1):
            if ave > val:
                val = ave
            try:
                ave = ave - nums[n] + nums[n+k]
            except:
                return val * 1.00 / k
        
        