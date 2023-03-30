# runtime: 194ms (beats 100%!)
# memory: 17.4MB (beats 93.33%!)
class Solution(object):
    def maxSumDivThree(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        tot = sum(nums)
        if tot % 3 == 0:
            return tot
        modOne = []
        modTwo = []
        for x in nums:
            if x % 3 == tot % 3:
                modOne.append(x)
            if x % 3 == 3 - (tot % 3):
                modTwo.append(x)
        diff = tot
        if len(modOne) > 0:
            diff = min(modOne)
        if len(modTwo) > 1:
            diff = min(diff, sum(sorted(modTwo)[0:2]))
        return (tot - diff)