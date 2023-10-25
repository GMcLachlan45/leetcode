// 2ms
// 41MB
class Solution {
    public int secondHighest(String s) {
        int se = -1;
        int f = -1;

        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(Character.isDigit(c)){
                int x = c-'0';
                if(f < x){
                    se = f;
                    f = x;
                } else if(se < x && x  < f){
                    se = x;
                }
            }
        }

        return se;
    }
}
