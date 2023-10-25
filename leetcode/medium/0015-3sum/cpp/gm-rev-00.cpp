// Runtime 2317ms
// Memory 184.8MB
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::unordered_set<int> numbers(nums.begin(), nums.end());
        set<vector<int>> rs;
        int zeros = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                zeros++;
            for(int j = i + 1; j < nums.size(); j++) {
                int search = -1*(nums[i] + nums[j]);
                if(search == nums[i] || search == nums[j])
                    continue;
                if(numbers.count(search)){
                    vector<int> ins{nums[i], nums[j], search};
                    sort(ins.begin(), ins.end());
                    rs.insert(ins);
                }
            }
        }
        vector<vector<int>> ret(rs.begin(), rs.end());
        if(zeros >= 3)
            ret.push_back({0,0,0});
        return ret;
    }
};
