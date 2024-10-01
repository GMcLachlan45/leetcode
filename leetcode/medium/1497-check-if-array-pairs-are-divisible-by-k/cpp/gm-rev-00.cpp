// Runtime: 91ms
// Memory: 64.4MB
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        std::vector<int> count(k);
        for(int x : arr)
            count[(x%k < 0) ? (x%k + k) : (x%k)]++;
        if(count[0] % 2)
            return false;
        if(k%2 == 0 && count[k/2]%2)
            return false;
        for(int i = 1; i < k/2; i++)
            if(count[i] != count[k-i])
                return false;
        for(int i = k/2+1; i < k; i++)
            if(count[i] != count[k-i])
                return false;
        return true;
    }
};
