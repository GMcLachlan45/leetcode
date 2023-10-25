//3ms
//42.7MB
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        List<Integer> sub = new ArrayList<>();
        Arrays.sort(nums);
        int sum1 = 0;
        int sum2 = 0;
        for(int i : nums)
            sum1 += i;
        for(int j = nums.length - 1; j >= 0; j--){
            sum1 -= nums[j];
            sum2 += nums[j];
            sub.add(nums[j]);
            if(sum2 > sum1)
                break;
        }
        return sub;
    }
}
