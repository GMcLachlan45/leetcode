// Runtime: 9ms
// Memory: 14MB
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int priority[201] = {0};

        for(int x : nums) {
            priority[x + 100]++;
        }

        std::sort(nums.begin(), nums.end(), [&] (const int & l, const int & r) {
            if(priority[l + 100] == priority[r + 100])
                return r < l;
            return priority[l + 100] < priority[r + 100];
        });
        return nums;
    }
};
