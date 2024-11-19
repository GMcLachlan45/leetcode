// Runtime: 89ms
// Memory: 98.4MB
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        std::unordered_map<int,int> mp;
        int dupes = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
            if(mp[nums[i]]++ == 1)
                dupes++;
        }

        long long ans = 0;
        if(!dupes && sum > ans)
            ans = sum;
        for(int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i-k];
            if(mp[nums[i]]++ == 1)
                dupes++;
            if(--mp[nums[i-k]] == 1)
                dupes--;
            if(!dupes && sum > ans)
                ans = sum;
        }

        return ans;
    }
};
