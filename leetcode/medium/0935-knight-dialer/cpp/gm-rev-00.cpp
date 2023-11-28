// Runtime: 77ms
// Memory: 44.09MB
class Solution {
public:
    int knightDialer(int n) {
        int MOD = 1000000007;
        std::vector<long> endsIn = {1,1,1,1,1,1,1,1,1,1};
        n--;
        while(n >0){
            std::vector<long> next(10);
            next[0] = (endsIn[4] + endsIn[6])%MOD;
            next[1] = (endsIn[6] + endsIn[8])%MOD;
            next[2] = (endsIn[7] + endsIn[9])%MOD;
            next[3] = (endsIn[4] + endsIn[8])%MOD;
            next[4] = (endsIn[3] + endsIn[9] + endsIn[0])%MOD;
            next[5] = 0;
            next[6] = (endsIn[1] + endsIn[7] + endsIn[0])%MOD;
            next[7] = (endsIn[2] + endsIn[6])%MOD;
            next[8] = (endsIn[1] + endsIn[3])%MOD;
            next[9] = (endsIn[2] + endsIn[4])%MOD;
            endsIn = next;

            n--;
        }
        return (endsIn[0]+endsIn[1]+endsIn[2]+endsIn[3]+endsIn[4]+endsIn[5]+endsIn[6]+endsIn[7]+endsIn[8]+endsIn[9])%MOD;
    }
};
