# runtime: 146ms
# memory: 15.5MB
class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return sorted([x * x for x in nums])