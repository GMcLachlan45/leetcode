// Runtime: 118ms
// Memory: 85.56MB
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        std::vector<float> timeToCity;
        for(int i = 0; i < dist.size(); i++)
            timeToCity.push_back((float) dist[i]/speed[i]);
        std::sort(timeToCity.begin(), timeToCity.end());

        int monstersDestroyed = 0;
        for(int i = 0; i < timeToCity.size(); i++) {
            if(timeToCity[i] <= i)
                break;
            monstersDestroyed++;
        }
        return monstersDestroyed;
    }
};
