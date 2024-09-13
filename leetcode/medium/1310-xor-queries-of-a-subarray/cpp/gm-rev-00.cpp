// Runtime: 56ms
// Memory: 41.5MB
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        std::vector<int> xors(arr.size());
        xors[0] = arr[0];
        for(int i = 1; i < xors.size(); i++)
            xors[i] = xors[i-1] ^ arr[i];

        std::vector<int> ans(queries.size());
        for(int i = 0; i < ans.size(); i++)
            ans[i] = xors[queries[i][1]] ^ ((queries[i][0]) ? xors[queries[i][0]-1] : 0);
        return ans;
    }
};
