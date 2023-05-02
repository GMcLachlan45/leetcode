//0ms
//40.6MB
class Solution {
    public boolean rotateString(String s, String goal) {
        if(s.length() != goal.length()) return false;
        StringBuilder str = new StringBuilder(s);
        str.append(s);
        return str.indexOf(goal) != -1;
    }
}
