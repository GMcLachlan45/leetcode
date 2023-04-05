//1ms
//42.1MB
class Solution {
    public boolean isPrefixString(String s, String[] words) {
        StringBuilder p = new StringBuilder("");
        for(String str : words){
            p.append(str);
            if(s.equals(p.toString()))
                return true;
        }
        return false;
    }
}
