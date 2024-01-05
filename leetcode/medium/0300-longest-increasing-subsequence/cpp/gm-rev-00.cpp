// Runtime: 439ms
// Memory: 12.58MB
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> lengthToBack(nums.size(),1);
        std::map<int, int> lengths;

        lengths[nums[nums.size()-1]] = nums.size()-1;
        for(int i = nums.size()-2; i >= 0; i--) {
            auto next = lengths.upper_bound(nums[i]);
            while(next != lengths.end()) {
                int calc =  lengthToBack[lengths[next->first]] + 1;
                if(calc >= lengthToBack[i])
                    lengthToBack[i] = calc;
                next++;
            }
            lengths[nums[i]] = i;
        }

        int max = 1;
        for(int x : lengthToBack)
            max = std::max(max, x);
        return max;
    }
};
