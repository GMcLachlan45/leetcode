//1ms
//39.9MB
class Solution {
    public int minMaxDifference(int num) {
        String s = num + "";
        int min = Integer.parseInt(s.replace(s.charAt(0), '0'));
        int max = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) != '9'){
                max = Integer.parseInt(s.replace(s.charAt(i), '9'));
                break;
            } else {
                max = num;
            }
        }
        return max - min;
    }
}
