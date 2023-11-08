// Runtime: 0ms
// Memory: 6.18MB
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(fx == sx && fy == sy)
            return t != 1;
        return std::max(std::abs(fx-sx),std::abs(fy-sy)) <= t;
    }
};
