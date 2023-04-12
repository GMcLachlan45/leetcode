//2ms
//42.3MB
class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder ps = new StringBuilder();
        char[] chars = s.toCharArray();
        int x = 0;
        for(char c : chars){
            if(c == '('){
                if(x > 0)
                    ps.append(c);
                x++;
            } else {
                x--;
                if(x > 0)
                    ps.append(c);
            }
        }
        return ps.toString();
    }
}
