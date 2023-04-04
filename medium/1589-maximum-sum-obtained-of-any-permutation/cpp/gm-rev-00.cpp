// Runtime 451ms
// Memory 129.1MB
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> start;
        vector<int> end;

        int n = requests.size();

        for(int i =0; i < n; i++){
            start.push_back(requests[i][0]);
            end.push_back(requests[i][1]+1);
        }

        std::sort(start.begin(), start.end());
        std::sort(end.begin(), end.end());

        std::vector<int> layers;
        int level = 0;
        int s = 0;
        int e = 0;

        for(int i = 0; i < nums.size(); i++){
            while(s < n && start[s] == i){
                level++;
                s++;
            }
            while(e < n && end[e] == i){
                level--;
                e++;
            }
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
