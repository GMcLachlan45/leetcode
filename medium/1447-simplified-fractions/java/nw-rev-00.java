//12ms
//43.6MB
class Solution {
    public int gcd(int i, int j){
        if(j != 0){
            return gcd(j, i % j);
        }else{
            return i;
        }
    }
    
    public List<String> simplifiedFractions(int n) {
        List<String> fractions = new ArrayList<>();
        for(int i = 1; i < n; i++){
            StringBuilder fraction = new StringBuilder();
            fraction.append(i);
            fraction.append("/");
            for(int j = i + 1; j <= n; j++){
                if(gcd(i,j) == 1){
                    int l = fraction.length();
                    fraction.append(j);
                    fractions.add(fraction.toString());
                    fraction.setLength(l);
                }
            }
        }
        return fractions;
    }
}
