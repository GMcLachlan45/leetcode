// Runtime: 51ms
// Memory: 38.9MB
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        std::vector<int> difficultyIdx(profit.size());
        std::iota(difficultyIdx.begin(), difficultyIdx.end(), 0);
        std::sort(difficultyIdx.begin(), difficultyIdx.end(), [&] (int l, int r) {
            return difficulty[l] < difficulty[r];
        });
        std::sort(worker.begin(), worker.end());
        int ret = 0;
        int ptr = 0;
        int maxProfit = 0;
        for(int x : worker) {
            while(ptr < difficultyIdx.size() && x >= difficulty[difficultyIdx[ptr]]) {
                maxProfit = std::max(maxProfit, profit[difficultyIdx[ptr]]);
                ptr++;
            }
            ret+= maxProfit;
        }
        return ret;
    }
};
