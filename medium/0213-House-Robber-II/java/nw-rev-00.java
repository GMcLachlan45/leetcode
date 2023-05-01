//0ms
//40.2MB
class Solution {
    public int rob(int[] nums) {
        if(nums.length == 1)
            return nums[0];
        return Math.max(robRow(nums, 0, nums.length - 2), robRow(nums, 1, nums.length - 1));
    }

    public int robRow(int[] nums, int l, int h){
        int lastMax = 0;
        int currMax = 0;
        for(int i = l; i <= h; i++){
            int a = currMax;
            currMax = Math.max(lastMax + nums[i], currMax);
            lastMax = a;
        }

        return currMax;
    }
}
