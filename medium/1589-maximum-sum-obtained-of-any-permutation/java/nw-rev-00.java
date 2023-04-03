//27ms
//78MB
class Solution {
    public int maxSumRangeQuery(int[] nums, int[][] requests) {
        int n = nums.length;
        long sum = 0;
        int f[] = new int[n];
        for(int i = 0; i < requests.length; i++){
            f[requests[i][0]] += 1;
            if(requests[i][1] + 1 < n)
                f[requests[i][1] + 1]--;
        }
        for(int i = 1; i < n; i++){
            f[i] += f[i - 1];
        }
        Arrays.sort(nums);
        Arrays.sort(f);
        for(int i = 0; i < n; i++){
            sum = (((long) nums[i] * f[i]) + sum) % 1000000007;
        }
        return (int) sum;
    }
}
