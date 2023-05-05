# runtime: 30ms
# memory: 13.6MB
class Solution(object):
    def canBeIncreasing(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        l = len(nums)
        k = nums[:] # make a copy
        for i in range(l-1):
            if nums[i] >= nums[i+1]:
                k.pop(i)
                nums.pop(i+1)
                if nums == sorted(list(set(nums))) or k == sorted(list(set(k))):
                    return True
                return False
                
        return True
