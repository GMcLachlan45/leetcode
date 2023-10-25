// Runtime 40ms
// Memory 25MB
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int sum = 0;

        int number_of_r1 = 0;
        int smallest_r1 = 10001;
        int second_smallest_r1 = 10001;

        int number_of_r2 = 0;
        int smallest_r2 = 10001;
        int second_smallest_r2 = 10001;
       
        for(int x : nums) {
            sum += x;
            switch(x%3) {
                case 1:
                    number_of_r1++;
                    if(x <= smallest_r1){
                        second_smallest_r1 = smallest_r1;
                        smallest_r1 = x;
                    } else if(x <= second_smallest_r1) {
                        second_smallest_r1 = x;
                    }
                    break;
                case 2:
                    number_of_r2++;
                    if(x <= smallest_r2){
                        second_smallest_r2 = smallest_r2;
                        smallest_r2 = x;
                    } else if(x <= second_smallest_r2) {
                        second_smallest_r2 = x;
                    }
                    break;
            }
        }

        switch((number_of_r2-number_of_r1)%3){
            case -2:
                sum -= (smallest_r2 < smallest_r1+second_smallest_r1) ? smallest_r2 : smallest_r1 + second_smallest_r1;
                break;
            case -1:
                sum -= (smallest_r1 < smallest_r2+second_smallest_r2) ? smallest_r1 : smallest_r2 + second_smallest_r2;
                break;
            case 0:
                break;
            case 1:
                sum -= (smallest_r2 < smallest_r1+second_smallest_r1) ? smallest_r2 : smallest_r1 + second_smallest_r1;
                break;
            case 2:
                sum -= (smallest_r1 < smallest_r2 + second_smallest_r2) ? smallest_r1 : smallest_r2 + second_smallest_r2;
                break;
        }

        return sum;
    }
};