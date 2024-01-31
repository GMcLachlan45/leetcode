// Runtime: 126ms
// Memory: 100.99MB
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int closestTemperature[101] = {0};
        std::vector<int> daysUntilWarmer(temperatures.size());
        for(int i = temperatures.size()-1; i >=0; i--) {
            int closest = temperatures.size();
            for(int j = temperatures[i]+1; j<101; j++) {
                if(closestTemperature[j] && closestTemperature[j] < closest)
                    closest = closestTemperature[j];
            }
            if(closest < temperatures.size())
                daysUntilWarmer[i] = closest - i;
            closestTemperature[temperatures[i]] = i;
        }
        return daysUntilWarmer;
    }
};
