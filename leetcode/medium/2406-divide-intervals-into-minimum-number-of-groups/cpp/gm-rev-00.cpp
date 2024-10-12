// Runtime: 323ms
// Memory: 106.7MB
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [] (std::vector<int>& l, std::vector<int>& r) {
            return l[0] < r[0];
        });

        int groups = 1;
        // store the {next smallest end time, index to that group}
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> next;
        next.push({0,0});

        for(std::vector<int> interval : intervals) {
            if(interval[0] > next.top().first) {
                next.push({interval[1], next.top().second});
                next.pop();
            } else
                next.push({interval[1], groups++});
        }
        return groups;
    }
};
