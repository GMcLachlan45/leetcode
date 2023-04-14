// Runtime 433ms
// Memory 84.6MB
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(int i = 0; i < dominoes.size(); i++)
            std::sort(dominoes[i].begin(), dominoes[i].end());
        std::sort(dominoes.begin(), dominoes.end(), [](vector<int> a, vector<int> b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });

        int pairs = 0;
        for(int i = 0; i < dominoes.size();){
            int j = i + 1;
            while(j < dominoes.size() && dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]){
                pairs += j-i;
                j++;
            }
            i = j;
        }

        return pairs;
    }
};
