// Runtime 15ms
// Memory 10MB

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates[1][0] - coordinates[0][0] == 0) {
            int x_int = coordinates[0][0];
            for(int i = 1; i < coordinates.size(); i++) {
                if(coordinates[i][0] != x_int)
                    return false;
            }
        } else {
            // y = mx + b =  (rise/run) * x + y_int;
            int rise = coordinates[1][1] - coordinates[0][1];
            int run = coordinates[1][0] - coordinates[0][0];

            // b = y - m * x
            int y_int = coordinates[0][1] - coordinates[0][0] * rise/run;

            for(int i = 1; i < coordinates.size(); i++) {
                //if mx + b != y;
                if(coordinates[i][0] * rise/run + y_int != coordinates[i][1])
                    return false;
            }
        } 
        return true;
    }
};
