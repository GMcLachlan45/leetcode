# runtime: 15ms
# memory: 13.5MB
class Solution(object):
    def minMaxDifference(self, num):
        """
        :type num: int
        :rtype: int
        """
        numStr = str(num)
        mini = int(numStr.replace(numStr[0], "0"))
        for i in range(len(numStr)):
            c = numStr[i]
            if c != "9":
                return int(numStr.replace(c, "9")) - mini
        return num - mini

                