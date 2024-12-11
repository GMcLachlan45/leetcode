// Runtime: 58ms
// Memory: 105.1MB
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int ans = 0;
        int front = 0;
        int back = 0;
        while(front < nums.size()) {
            while(nums[back] < nums[front] - 2*k)
                back++;
            if(++front - back > ans)
                ans = front - back;
        }
        return ans;
    }
};
