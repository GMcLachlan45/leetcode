// 2ms
// 50.7MB
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum = 0;

        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        int msum = sum;

        for(int j = k; j < nums.length; j++){
            sum = (sum + nums[j]) - nums[j - k];
            if(sum > msum){
                msum = sum;
            }
        }

        return (double) msum / k;
    }
}
