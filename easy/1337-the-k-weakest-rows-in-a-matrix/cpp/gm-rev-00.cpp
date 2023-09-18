// Runtime 0ms
// Memory 10.80MB
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // strength, original idx
        std::vector<std::pair<int,int>> indices;

        for(int i = 0; i < mat.size(); i++)
            indices.push_back({std::distance(mat[i].begin(), std::lower_bound(mat[i].begin(), mat[i].end(), 0, std::greater<int>())), i});

        std::sort(indices.begin(), indices.end(),
            [](const std::pair<int,int> a, const std::pair<int,int> b) {
                return (a.first == b.first) ? a.second < b.second : a.first < b.first;
            }
        );
        std::vector<int> ret;
        for(int i = 0; i < k; i++)
            ret.push_back(indices[i].second);
        return ret;
    }
};
