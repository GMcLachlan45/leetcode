//6ms
//51.6MB
class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int neg = 0;
        long sum = 0;
        long min = Long.MAX_VALUE;
        for(int i = 0; i < matrix.length; i++){
            for(int num : matrix[i]){
                if(num < 0){
                    neg++;
                }
                sum += Math.abs(num);
                min = Math.min(min, Math.abs(num));
            }
        }
        if(neg % 2 == 0){
            return sum;
        }else{
            return sum - 2 * min;
        }
    }
}
