//0ms
//42.5MB
class Solution {
    public boolean canBeIncreasing(int[] nums) {
        int[] n = nums;
        boolean removed = false;
        for(int i = 1; i < n.length; i++){
            if(n[i - 1] >= n[i]){
                if(removed)
                    return false;
                removed = true;
                if(i > 1 && n[i] <= n[i - 2])
                    n[i] = n[i - 1];
            }
        }
        return true;
    }
}
