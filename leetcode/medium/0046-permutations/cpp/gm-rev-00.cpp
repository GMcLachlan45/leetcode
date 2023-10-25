// Runtime 3ms
// Memory 10.6MB
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1)
            return {nums};
        std::vector<std::vector<int>> ret;
        for(int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            nums[i] = nums[0];
            nums[0] = temp;
            std::vector<int> sub_nums(nums.begin()+1, nums.end());
            std::vector<std::vector<int>> sub_array = permute(sub_nums);
            for(std::vector<int> x: sub_array){
                x.insert(x.begin(), nums[0]);
                ret.push_back(x);
            }
        }
        return ret;
    }
};
