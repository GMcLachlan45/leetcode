// Runtime 6ms
// Memory 11MB
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        short int count = 0;
        for(short int i = 0; i < startTime.size(); i++){
            if(startTime[i] <= queryTime && endTime[i] >= queryTime)
                count++;
        }
        return count;
    }
};
