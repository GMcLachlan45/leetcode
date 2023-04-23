//2ms
//43.4MB
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> lucky = new ArrayList<>();
        boolean found = false;
        for(int i = 0; i < matrix.length; i++){
            int min = Integer.MAX_VALUE;
            int ind = -1;
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] < min){
                    min = matrix[i][j];
                    ind = j;
                }
            }
            found = true;
            for(int k = 0; k < matrix.length; k++){
                if(matrix[k][ind] > min)
                    found = false;
            }
            if(found)
                lucky.add(min);
        }
        return lucky;
    }
}
