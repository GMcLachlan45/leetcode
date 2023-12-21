// Runtime: 239ms
// Memory: 77.1MB
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::vector<int> xCoords;
        for(std::vector<int> point : points)
            xCoords.push_back(point[0]);
        std::sort(xCoords.begin(), xCoords.end());

        int maxWidth = 0;
        for(int i = 1; i < xCoords.size(); i++) {
            if(xCoords[i] - xCoords[i-1] > maxWidth)
                maxWidth = xCoords[i] - xCoords[i-1];
        }
        return maxWidth;
    }
};
