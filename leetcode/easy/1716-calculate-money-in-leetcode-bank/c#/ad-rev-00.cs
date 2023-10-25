//runtime 15ms
//memory 26.6MB
public class Solution {
    public int TotalMoney(int n) {
        int numWeeks = n/7;
        int numDays = n%7;
        int sum = (4*numWeeks)*7 + 7*(((numWeeks-1)*numWeeks)/2);
        sum += ((numDays+numWeeks)*(numDays+numWeeks+1)/2) - ((numWeeks)*(numWeeks+1)/2);
        return sum;
    }
}