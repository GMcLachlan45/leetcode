// Runtime: 22ms
// Memory: 29.7MB
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ret;
        int count = 0;
        ret.push_back({nums[0]});
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                if(ret.size() == count + 1)
                    ret.push_back({});
                count++;
            } else
                count = 0;
            ret[count].push_back(nums[i]);
        }
        return ret;
    }
};
