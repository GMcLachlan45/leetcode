// Runtime: 146ms
// Memory 102.4MB
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // Have indexes of last house with each garbage
        int lastM = 0;
        int lastP = 0;
        int lastG = 0;

        int garbageTime = 0;
        int travelTime = 0;
        // Find the last house with each garbage type
        for(int i = 0; i < garbage.size(); i++){
            garbageTime += garbage[i].size();
            for(char g: garbage[i]) {
                if(g == 'M')
                    lastM = i;
                if(g == 'P')
                    lastP = i;
                if(g == 'G')
                    lastG = i;
                if(lastM == i && lastM == lastP && lastP == lastG)
                    break;
            }
        }

        // Find the travel time to each house
        int lastHouse = std::max(std::max(lastM, lastP), lastG);
        for(int i = 0; i < lastHouse; i++){
            if(i < lastM)
                travelTime += travel[i];
            if(i < lastP)
                travelTime += travel[i];
            if(i < lastG)
                travelTime += travel[i];
        }
        return garbageTime + travelTime;
    }
};
