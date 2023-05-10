//6ms
//50.6MB
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        int index = 0;
        List<Integer> list = new ArrayList<Integer>();

        for(int i : nums){
            index = Math.abs(i);
            if(nums[index - 1] > 0){
                nums[index - 1] *= -1;
            }
        }

        for(int i = 0; i < n; i++){
            if(nums[i] > 0)
                list.add(i + 1);
        }

        return list;
    }
}
