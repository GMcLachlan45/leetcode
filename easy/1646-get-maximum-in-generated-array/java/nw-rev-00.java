//0ms
//39.8MB
class Solution {
    public int getMaximumGenerated(int n) {
        if(n < 2) return n;
        int[] l = new int[n + 1];
        int max = -1;
        l[0] = 0;
        l[1] = 1;
        for(int i = 2; i <  n + 1; i++){
            if(i % 2 == 0){
                l[i] = l[i / 2];
            }else{
                l[i] = l[i / 2] + l[(i / 2) + 1];
            }
            if(max < l[i])
                max = l[i];
        }
        return max;
    }
}
