//11ms
//51.5MB
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int equal = 0;
        for(int i = 0; i < dominoes.length; i++){
            int key = Math.max(dominoes[i][0], dominoes[i][1]) * 10 + Math.min(dominoes[i][0], dominoes[i][1]);
            int value = map.getOrDefault(key, 0);
            equal += value;
            map.put(key, value + 1);
        }
        return equal;
    }
}
