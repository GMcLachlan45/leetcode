// 0ms
// 40.7
class Solution {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        int x = 0;
        for(int i = 0; i < startTime.length; i++){
            if(startTime[i] <= queryTime && queryTime <= endTime[i]){
                x++;
            }
        }
        return x;
    }
}
