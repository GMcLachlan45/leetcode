// Runtime 420ms
// Memory 123.3MB
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> change(nums.size() + 1, 0);

        for(int i =0; i < requests.size(); i++){
            change[requests[i][0]]++;
            change[requests[i][1]+1]--;
        }

        std::vector<int> layers;
        int level = 0;

        for(int i = 0; i < nums.size(); i++){
            level += change[i];
            layers.push_back(level);
        }

        std::sort(nums.begin(), nums.end());
        std::sort(layers.begin(), layers.end());

        long sum = 0;
        for(int i = nums.size()-1; i >=0 && layers[i] > 0; i--){
            sum += (long) nums[i] * layers[i];
        }

        return (int) (sum % 1000000007);
    }
};
