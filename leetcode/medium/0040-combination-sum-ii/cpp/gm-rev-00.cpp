// Runtime: 87ms
// Memory: 28.7MB

class Solution {
    int numCounts[31];
    std::vector<std::vector<int>> helper(int lowerBound, int target) {
        if(target == 0)
            return {{}};
        if(target < 0)
            return {};
        while(lowerBound < 31 && !numCounts[lowerBound])
            lowerBound++;
        if(lowerBound > 30)
            return {};

        std::vector<std::vector<int>> ans;
        std::vector<int> conCats;
        for(int i = 0; i <= numCounts[lowerBound]; i++) {
            std::vector<std::vector<int>> helped = helper(lowerBound+1, target - i*lowerBound);
            for(std::vector<int> arr : helped ) {
                ans.push_back(conCats);
                ans[ans.size()-1].insert(ans[ans.size()-1].end(),
                                         arr.begin(), arr.end());
            }
            conCats.push_back(lowerBound);
        }
        return {ans};
    }


public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for(int x : candidates)
            if(x < 31)
                numCounts[x]++;
        return helper(1, target);
    }
};
