// 0ms
// 42.7MB
class Solution {
    public double calculateTax(int[][] brackets, int income) {
        double x;

        if(income < brackets[0][0])
            return (double) (income * brackets[0][1]) / 100;

        x = brackets[0][0] * brackets[0][1];

        for(int i = 1; i < brackets.length; i++){
            if(income > brackets[i][0]){
                x += (brackets[i][0] - brackets[i - 1][0]) * brackets[i][1];
            }else{
                x += (income - brackets[i - 1][0]) * brackets[i][1];
                break;
            }
        }

        return (double) x / 100;
    }
}
