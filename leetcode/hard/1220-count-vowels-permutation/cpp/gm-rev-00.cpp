// Runtime: 3ms
// Memory: 6.3MB
class Solution {
public:
    int countVowelPermutation(int n) {
        //array w/ a,e,i,o,u times
        long last[5]={1,1,1,1,1};
        long temp[5];
        long MOD = 1000000007;
        for(int i = 1; i<n; i++) {
            temp[0] = last[1]%MOD;
            temp[1] = (last[0]+last[2])%MOD;
            temp[2] = (last[0]+last[1]+last[3]+last[4])%MOD;
            temp[3] = (last[2]+last[4])%MOD;
            temp[4] = last[0]%MOD;
            std:copy(temp, temp+5, last);
        }
        return (last[0] + last[1] + last[2] + last[3] + last[4])%MOD;
    }
};
