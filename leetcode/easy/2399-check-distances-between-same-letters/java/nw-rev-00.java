//1ms
//42.6MB
class Solution {
    public boolean checkDistances(String s, int[] distance) {
        for(int i = 0; i < s.length(); i++){
            int dist = distance[s.charAt(i) - 'a'];
            if(i + dist + 1 >= s.length() || s.charAt(i + dist + 1) != s.charAt(i))
                return false;
            distance[s.charAt(i) - 'a'] = -1;
        }

        return true;
    }
}
