//1ms
//43.9MB
class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] arr = new int[nums.length];
        int a = 0;
        int b = nums.length - 1;
        for(int i = nums.length - 1; i >= 0; i--){
            if(Math.abs(nums[a]) > Math.abs(nums[b])){
                arr[i] = nums[a] * nums[a];
                a++;
            }else{
                arr[i] = nums[b] * nums[b];
                b--;
            }
        }
        return arr;
    }
}
