# runtime: 297ms
# memory: 27.4MB
# bad solution, but one-liners are always fun
class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        return set(range(1,len(nums)+1)).difference(nums)