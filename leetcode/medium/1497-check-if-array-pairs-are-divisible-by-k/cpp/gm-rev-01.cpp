// Runtime: 87ms
// Memory: 63.9MB
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        std::vector<int> count(k/2+1);
        for(int x : arr) {
            x %= k;
            if(x < 0)
                x += k;
            if(x <= k/2)
                count[x]++;
            else
                count[k-x]--;
        }
        count[0] %= 2;
        if(k%2 == 0)
            count[k/2] %= 2;
        for(int missingSum : count)
            if(missingSum)
                return false;
        return true;
    }
};
