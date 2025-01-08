// Runtime: 12ms
// Memory: 126.1MB
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        // save the index of the left int of a pair with same pairity
        std::vector<int> not_special_idxs;
        for(int i = 0; i < nums.size() - 1; i++)
            if(((nums[i] ^ nums[i+1]) & 1) == 0)
                not_special_idxs.push_back(i);

        not_special_idxs.push_back(nums.size());

        std::vector<bool> ans(queries.size());
        for(int i = 0; i < queries.size(); i++)
            ans[i] = *std::lower_bound(not_special_idxs.begin(), not_special_idxs.end(), queries[i][0]) >= queries[i][1];
        return ans;
    }
};
