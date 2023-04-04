//25ms
//43.7MB
class Solution {
    public int distributeCandies(int[] candyType) {
        Set<Integer> s = new HashSet<>();
        for(Integer c : candyType){
            s.add(c);
            if(s.size() == candyType.length / 2)
                return s.size();
        }
        return Math.min(s.size(), candyType.length / 2);
    }
}
