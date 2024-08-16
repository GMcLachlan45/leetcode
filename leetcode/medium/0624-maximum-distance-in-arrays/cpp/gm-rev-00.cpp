// Runtime: 236ms
// Memory: 107.9MB
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minValue, minArray, secondMinValue, maxValue, maxArray, secondMaxValue;
        if(arrays[0][0] < arrays[1][0]) {
            minValue = arrays[0][0];
            minArray = 0;
            secondMinValue = arrays[1][0];
        } else {
            minValue = arrays[1][0];
            minArray = 1;
            secondMinValue = arrays[0][0];
        }

        if(arrays[0][arrays[0].size()-1] > arrays[1][arrays[1].size()-1]) {
            maxValue = arrays[0][arrays[0].size()-1];
            maxArray = 0;
            secondMaxValue = arrays[1][arrays[1].size()-1];
        } else {
            maxValue = arrays[1][arrays[1].size()-1];
            maxArray = 1;
            secondMaxValue = arrays[0][arrays[0].size()-1];
        }

        for(int i = 2; i < arrays.size(); i++) {
            if(arrays[i][0] < minValue) {
                secondMinValue = minValue;
                minValue = arrays[i][0];
                minArray = i;
            } else if(arrays[i][0] < secondMinValue)
                secondMinValue = arrays[i][0];

            if(arrays[i][arrays[i].size()-1] > maxValue) {
                secondMaxValue = maxValue;
                maxValue = arrays[i][arrays[i].size()-1];
                maxArray = i;
            } else if(arrays[i][arrays[i].size()-1] > secondMaxValue)
                secondMaxValue = arrays[i][arrays[i].size()-1];
        }

        if(minArray == maxArray)
            return std::max(maxValue - secondMinValue, secondMaxValue - minValue);
        return maxValue - minValue;
    }
};
