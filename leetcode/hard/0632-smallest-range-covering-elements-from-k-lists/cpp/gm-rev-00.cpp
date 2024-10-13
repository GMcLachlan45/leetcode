// Runtime: 46ms
// Memory: 19.4MB
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // save a heap that tracks which  values are needed by {val, idx}
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> nextIncrement;

        int max = -10000;
        std::vector<int> numPtr(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i][0] > max)
                max = nums[i][0];
            nextIncrement.push({nums[i][0], i});
        }

        std::vector<int> ret = {nextIncrement.top().first, max};
        // min to be used when one of the arrays gets exhausted
        int min = -10001;
        while(!nextIncrement.empty()) {
            numPtr[nextIncrement.top().second]++;
            if(numPtr[nextIncrement.top().second] >= nums[nextIncrement.top().second].size()){
                if(min == -10001)
                    min = nextIncrement.top().first;
            } else {
                if(nums[nextIncrement.top().second][numPtr[nextIncrement.top().second]] > max)
                    max = nums[nextIncrement.top().second][numPtr[nextIncrement.top().second]];
                nextIncrement.push(
                    {nums[nextIncrement.top().second][numPtr[nextIncrement.top().second]],
                     nextIncrement.top().second});
            }
            nextIncrement.pop();
            if(min != -10001) {
                if(max - min < ret[1] - ret[0])
                    ret = {min, max};
            } else {
                if(max - nextIncrement.top().first < ret[1] - ret[0])
                    ret = {nextIncrement.top().first,max};
            }
        }

        return ret;
    }
};
