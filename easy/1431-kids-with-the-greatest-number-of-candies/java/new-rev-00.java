//1ms
//42.7MB
class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int m = candies[0];
        List<Boolean> list = new ArrayList<>();
        for(int i = 0; i < candies.length; i++){
            if(candies[i] > m){
                m = candies[i];
            }
        }
        for(int i = 0 ; i < candies.length; i++){
            list.add(candies[i] + extraCandies >= m);
        }
        return list;
    }
}
