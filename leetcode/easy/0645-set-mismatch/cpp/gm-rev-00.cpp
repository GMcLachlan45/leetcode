// Runtime: 32ms
// Memory: 32.24MB
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0;
        int realSum = 0;
        int dupe = 0;
        std::unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            realSum += i+1;
            if(!dupe) {
                if(st.count(nums[i]))
                    dupe = nums[i];
                st.insert(nums[i]);
            }
        }
        return {dupe, realSum-(sum-dupe)};
    }
};
