// Runtime: 66ms
// Memory: 39.7MB
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        // Add the obstacles to an easily retrievable object
        struct pair_hash{
            size_t operator()(const std::pair<int,int> &x) const {
                return x.first*40000 + x.second;
            }
        };
        std::unordered_set<std::pair<int,int>, pair_hash> obs;
        for(auto x : obstacles)
            obs.insert({x[0], x[1]});


        std::pair<int,int> location = {0,0};
        std::pair<int,int> eye_line = {0,1};

        int max_dist_squared = 0;
        for(int command : commands) {
            // If we're turning, properly turn
            if(command < 0) {
                switch(eye_line.first*10 + eye_line.second) {
                case 1 :
                    eye_line = {(command == -2) ? -1 : 1, 0};
                    break;
                case -1:
                    eye_line = {(command == -2) ? 1 : -1, 0};
                    break;
                case 10:
                    eye_line = {0, (command == -2) ? 1 : -1};
                    break;
                case -10:
                    eye_line = {0, (command == -2) ? -1 : 1};
                    break;
                }
                continue;
            }

            while(command-- && !obs.contains({location.first + eye_line.first, location.second + eye_line.second}))
                location = {location.first + eye_line.first, location.second + eye_line.second};

            if(max_dist_squared < location.first * location.first + location.second * location.second)
                max_dist_squared = location.first * location.first + location.second * location.second;
        }
        return max_dist_squared;
    }
};
