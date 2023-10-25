// Runtime 9ms
// Memory 8MB
class Solution {
public:
    bool judgeCircle(string moves) {
        short int x = 0;
        short int y = 0;
        for(char c: moves){
            if(c == 'R')
                x++;
            else if(c == 'L')
                x--;
            else if(c == 'U')
                y++;
            else
                y--;
        }
        return !x && !y;
    }
};