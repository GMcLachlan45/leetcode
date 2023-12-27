// Runtime: 206ms
// Memory: 95.6MB
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int lastPtr = 0;
        for(int i = 1; i < colors.size(); i++) {
            if(colors[i] == colors[lastPtr]) {
                if(neededTime[i] > neededTime[lastPtr]) {
                    time += neededTime[lastPtr];
                    lastPtr = i;
                } else {
                    time += neededTime[i];
                }
            } else
                lastPtr = i;
        }
        return time;
    }
};
