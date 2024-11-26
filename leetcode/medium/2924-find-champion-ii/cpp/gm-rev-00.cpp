// Runtime: 37ms
// Memory: 104.1MB
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        std::vector<bool> undefeated(n, true);

        for(std::vector<int> edge : edges)
            undefeated[edge[1]] = false;
        int champ = -1;
        for(int i = 0; i < n; i++) {
            if(!undefeated[i])
                continue;
            if(champ >= 0)
                return -1;
            champ = i;
        }
        return champ;
    }
};
