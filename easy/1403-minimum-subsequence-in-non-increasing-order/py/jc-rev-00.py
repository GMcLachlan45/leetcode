# runtime: 40ms
# memory: 13.3MB
class Solution(object):
    def minSubsequence(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort(reverse=True)
        tot = sum(nums) / 2
        s = 0
        for i in range(len(nums)):
            s += nums[i]
            if s > tot:
                return nums[:i+1]
        return nums