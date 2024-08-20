// Runtime: 19ms
// Memory: 10.3MB
class Solution {

    std::pair<int,int> cache[100][50];

    // return Optimal Stones accrued by Alice and Bob (in that order)
    std::pair<int,int> aliceAndBobStones(int startingPile, int M, bool aliceTurn, std::vector<int>* piles) {
        // It's always optimal to pick up the remaining piles if you can.
        if(startingPile + 2*M >= piles->size()) {
            int remainingStones = 0;
            for(int i = startingPile; i < piles->size(); i++)
                remainingStones += piles->at(i);
            if(aliceTurn)
                return {remainingStones, 0};
            else
                return {0, remainingStones};
        }

        // See if we've saved this already
        if(cache[startingPile][M].first || cache[startingPile][M].second) {
            if(aliceTurn)
                return cache[startingPile][M];
            else
                return {cache[startingPile][M].second,cache[startingPile][M].first};
        }

        std::pair<int,int> best = {0,0};
        int pickedUpThisTurn = 0;
        for(int X = 1; X <= 2*M; X++) {
            pickedUpThisTurn += piles->at(startingPile+X-1);
            std::pair<int,int> remainingGame = aliceAndBobStones(startingPile + X, std::max(M, X), !aliceTurn, piles);
            if(aliceTurn) {
                // Alice wants to play optimally
                if(remainingGame.first + pickedUpThisTurn > best.first) {
                    best = remainingGame;
                    best.first += pickedUpThisTurn;
                }
            } else {
                // So does Bob, though
                if(remainingGame.second + pickedUpThisTurn > best.second) {
                    best = remainingGame;
                    best.second += pickedUpThisTurn;
                }
            }
        }

        // Store in cache for easy access
        if(aliceTurn)
            cache[startingPile][M] = best;
        else
            cache[startingPile][M] = {best.second, best.first};


        return best;
    }

public:
    int stoneGameII(vector<int>& piles) {
        return aliceAndBobStones(0, 1, true, &piles).first;
    }
};
