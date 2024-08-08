// Runtime: 6ms
// Memory: 12.4 MB
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int x = cStart;
        int y = rStart;
        int movesInDirection = 1;
        int movesTaken = 0;
        int direction = 0;
        int spacesLeft = rows * cols;
        std::vector<std::vector<int>> ans(spacesLeft);
        while(spacesLeft) {
            if(0 <= x && x < cols && 0 <= y && y < rows)
                ans[ans.size() - spacesLeft--] = {y,x};
            switch(direction) {
            case 0:
                x++;
                break;
            case 1:
                y++;
                break;
            case 2:
                x--;
                break;
            default:
                y--;
            }
            movesTaken++;
            if(movesTaken == movesInDirection) {
                if(direction == 1 || direction == 3)
                    movesInDirection++;
                movesTaken = 0;
                ++direction %=4;
            }
        }
        return ans;
    }
};
