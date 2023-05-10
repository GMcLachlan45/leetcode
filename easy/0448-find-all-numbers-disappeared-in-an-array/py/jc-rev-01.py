# runtime: 290ms
# memory: 23.1MB
# less elegant
class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        st = set(nums)
        out = []
        n = len(nums)

        for i in range(1,n+1):
            if i not in st:
                out.append(i)
        return out