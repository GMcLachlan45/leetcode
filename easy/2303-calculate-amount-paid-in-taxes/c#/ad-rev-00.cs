//runtime 88ms 
//memory 40.5MB

public class Solution {
    public double CalculateTax(int[][] brackets, int income) {
        if (income <= brackets[0][0]) {
            return income * (brackets[0][1] / 100.0);
        } else {
            return brackets[0][0] * (brackets[0][1] / 100.0) + CalcTaxRecursive(brackets, income, 1);
        }
    }

    public double CalcTaxRecursive(int[][] brackets, int income, int i) {
        if (income <= brackets[i][0]) {
            return (income - brackets[i-1][0]) * (brackets[i][1] / 100.0);
        } else {
            return (brackets[i][0]-brackets[i-1][0]) * (brackets[i][1] / 100.0) + CalcTaxRecursive(brackets, income, i+1);
        }
    }
}