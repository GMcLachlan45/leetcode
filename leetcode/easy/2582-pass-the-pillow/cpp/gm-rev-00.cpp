// Runtime: 0ms
// Memory: 7.1MB
class Solution {
public:
    int passThePillow(int n, int time) {
        return (time % (2*n - 2) < n) ? time % (2*n -2)+1 : n - time % (n-1);
    }
};
