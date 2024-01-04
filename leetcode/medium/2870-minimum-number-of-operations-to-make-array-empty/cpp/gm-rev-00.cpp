// Runtime: 119ms
// Memory: 85.15MB
class Solution {
public:
    int minOperations(vector<int>& nums) {
        std::unordered_map<int,int> mp;
        for(int num : nums)
            mp[num]++;
        int operationCount = 0;
        for(auto x : mp) {
            if(x.second == 1)
                return -1;
            operationCount += x.second/3;
            if(x.second % 3 > 0)
                operationCount++;
        }
        return operationCount;
    }
};
