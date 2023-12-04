// Runtime: 3ms
// Memory: 10.44MB
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i = 1; i < points.size(); i++)
            time+= std::max(std::abs(points[i][0] - points[i-1][0]), std::abs(points[i][1] - points[i-1][1]));
        return time;
    }
};
