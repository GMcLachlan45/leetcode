// Runtime 265ms
// Memory 110.4MB
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        std::unordered_set types(candyType.begin(), candyType.end());
        return std::min(candyType.size()/2, types.size());
    }
};
