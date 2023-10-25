// Runtime 12ms
// Memory 13.3MB
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {       
        if (brackets[0][0] > income) 
            return (double) (income * brackets[0][1]) / 100 ;
        int sum = brackets[0][0] * brackets[0][1];

        for(int i = 1; i < brackets.size(); i++){
            if(brackets[i][0] > income){
                sum += (income - brackets[i - 1][0]) * brackets[i][1];
                break;
            } else {
                sum += (brackets[i][0] - brackets[i - 1][0]) * brackets[i][1];
            }
        }
        return (double) sum / 100;
    }
};
