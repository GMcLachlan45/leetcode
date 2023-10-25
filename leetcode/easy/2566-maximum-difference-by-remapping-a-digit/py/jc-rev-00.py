# runtime: 24ms
# memory: 13.2MB
class Solution(object):
    def minMaxDifference(self, num):
        """
        :type num: int
        :rtype: int
        """
        numStr = str(num)
        mini = int(numStr.replace(numStr[0], "0"))
        for i in range(len(numStr)):
            if numStr[i] != "9":
                return int(numStr.replace(numStr[i], "9")) - mini
        return num - mini

                