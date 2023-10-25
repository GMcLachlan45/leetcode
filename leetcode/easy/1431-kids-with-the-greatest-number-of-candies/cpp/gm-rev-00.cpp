// Runtime 4ms
// Memory 8.9MB
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        vector<bool> ret;
        for(int x: candies)
            max = (x > max) ? x : max;
        for(int x: candies)
            ret.push_back(x + extraCandies >= max);
        return ret;
    }
};
