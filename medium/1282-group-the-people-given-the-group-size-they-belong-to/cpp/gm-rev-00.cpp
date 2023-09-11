// Runtime 3ms
// Memory 12.56MB
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        std::unordered_map<int, std::vector<int>> m;
        std::vector<std::vector<int>> ret;
        for(int i = 0; i < groupSizes.size(); i++) {
            m[groupSizes[i]].push_back(i);
            if(m[groupSizes[i]].size() == groupSizes[i]){
                ret.push_back(m[groupSizes[i]]);
                std::vector<int> empty;
                m[groupSizes[i]] = empty;
                }
        }

        return ret;
    }
};
