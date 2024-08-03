// Runtime: 6ms
// Memory: 18.1MB
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int count[1001];
        int nonZeros = 0;
        for(int x : target) {
            if(!count[x])
                nonZeros++;
            count[x]++;
        }
        for(int y : arr) {
            count[y]--;
            if(!count[y])
                nonZeros--;
        }
        return nonZeros==0;
    }
};
