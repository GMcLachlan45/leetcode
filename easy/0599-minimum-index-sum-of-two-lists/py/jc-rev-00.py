# runtime: 166ms
# memory: 13.9MB
class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        shared = set(list1).intersection(set(list2))
        if len(shared) == 1:
            return shared
        shared = list(shared)
        fst = shared[0]
        minSum = list1.index(fst) + list2.index(fst)
        out = [fst]
        for s in shared[1:]:
            i = list1.index(s)
            j = list2.index(s)
            if i + j < minSum:
                out = []
                minSum = i + j
            if i + j == minSum:
                out.append(s)
        return out
