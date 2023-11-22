// Runtime: 363ms
// Memory: 73.94MB
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        std::vector<int> ret;
        std::vector<std::tuple<int,int,int>> tups;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++)
                tups.push_back(std::make_tuple(i+j, i, nums[i][j]));
        }

        std::sort(tups.begin(), tups.end(), [](std::tuple<int,int,int> a, std::tuple<int,int,int> b) {
            if(std::get<0>(a) == std::get<0>(b))
                return std::get<1>(a) > std::get<1>(b);
            return std::get<0>(a) < std::get<0>(b);
        });

        for(std::tuple<int,int,int> x: tups)
            ret.push_back(std::get<2>(x));
        return ret;
    }
};
