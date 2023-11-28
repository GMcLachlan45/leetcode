// Runtime: 114ms
// Memory: 30.9MB
class Solution {
public:
    int numberOfWays(string corridor) {
        bool passedSeat = false;
        bool firstSeat = false;

        int plantSpace = 0;
        long ret = 1;
        int MOD = 1000000007;
        for(char item : corridor) {
            if(item == 'S') {
                firstSeat=true;
                if(plantSpace>0 && !passedSeat) {
                    ret = (ret * (plantSpace + 1)) % MOD;
                    plantSpace = 0;
                }
                passedSeat = !passedSeat;
            } else if(firstSeat && !passedSeat)
                plantSpace++;
        }
        if(!firstSeat || passedSeat)
            return 0;
        return ret;
    }
};
