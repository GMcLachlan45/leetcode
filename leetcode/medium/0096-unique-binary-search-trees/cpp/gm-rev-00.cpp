// Runtime: 0ms
// Memory: 7.4MB
class Solution {
    int cache[20] = {1,1};
public:
    int numTrees(int n) {
        if(cache[n])
            return cache[n];
        for(int leftCount = 0; leftCount < n; leftCount++)
            cache[n] += numTrees(leftCount) * numTrees(n-1 - leftCount);
        return cache[n];
    }
};
