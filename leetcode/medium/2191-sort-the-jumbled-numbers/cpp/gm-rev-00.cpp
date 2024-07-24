// Runtime: 138ms
// Memory: 77.4MB
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        std::vector<int> mapped_nums(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            for(int dec = 1; dec <= nums[i]; dec *= 10 )
                mapped_nums[i] += mapping[(nums[i] / dec) % 10] * dec;
            if(nums[i] == 0)
                mapped_nums[i] = mapping[0];
        }

        std::vector<int> indices(nums.size());
        std::iota(indices.begin(), indices.end(), 0);

        std::sort(indices.begin(), indices.end(), [&] (const int& l, const int& r) {
            return mapped_nums[l] < mapped_nums[r];
        });
        for(int i = 0; i < nums.size(); i++)
            mapped_nums[i] = nums[indices[i]];

        return mapped_nums;


    }
};
