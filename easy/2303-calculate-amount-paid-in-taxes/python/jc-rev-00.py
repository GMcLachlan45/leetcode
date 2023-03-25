class Solution(object):
    def calculateTax(self, brackets, income):
        """
        :type brackets: List[List[int]]
        :type income: int
        :rtype: float
        """
        taxable = max(min(income, brackets[0][0]), 0)
        taxAmt = taxable * brackets[0][1] / 100.0
        for i in range(1, len(brackets)):
            top = min(income, brackets[i][0])
            bot = brackets[i-1][0]
            taxable = max(top - bot,0)
            taxAmt = taxAmt + taxable * brackets[i][1] / 100.0

        return taxAmt
