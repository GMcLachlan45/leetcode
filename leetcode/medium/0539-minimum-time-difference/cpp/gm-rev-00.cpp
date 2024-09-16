// Runtime: 13ms
// Memory: 17.3MB
class Solution {
    int ClockToMinutes(std::string st) {
        return std::stoi(st)*60 + std::stoi(st.substr(3, 2));
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        std::sort(timePoints.begin(), timePoints.end());
        int ans = 24*60 + ClockToMinutes(timePoints[0]) - ClockToMinutes(timePoints[timePoints.size()-1]);
        for(int i = 1; i < timePoints.size(); i++)
            ans = std::min(ans, ClockToMinutes(timePoints[i]) - ClockToMinutes(timePoints[i-1]));
        return ans;
    }
};
