// Runtime: 104ms
// Memory 53.6MB
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        std::sort(piles.begin(), piles.end());
        int myCoins = 0;
        for(int i = 0; 3*i < piles.size(); i++)
            myCoins += piles[piles.size()-2-i*2];
        return myCoins;
    }
};
