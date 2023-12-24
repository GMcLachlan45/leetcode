// Runtime: 4ms
// Memory: 7.26MB
class Solution {
public:
    bool isPathCrossing(string path) {
        std::set<std::pair<int,int>> past;
        int x = 0;
        int y = 0;
        past.insert({0,0});
        for(char c : path){
            x += (c == 'E') - (c == 'W');
            y += (c == 'N') - (c == 'S');
            if(past.count({x,y}))
                return true;
            past.insert({x,y});
        }
        return false;
    }
};
