//1ms
//41.9MB
class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> s = new HashSet<>();
        for(int i = 0; i < arr.length; i++){
            if(s.contains(2 * arr[i]) || arr[i] % 2 == 0 && s.contains(arr[i] / 2))
                return true;
            s.add(arr[i]);
        }
        return false;
    }
}
