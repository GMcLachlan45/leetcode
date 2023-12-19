// Runtime: 47ms
// Memory: 22.2MB
class Solution {
    int averagePixel(int startX, int endX, int startY, int endY, std::vector<std::vector<int>>* imgPtr){
        if(startX<0)
            startX++;
        if(endX == imgPtr->at(0).size())
            endX--;
        if(startY<0)
            startY++;
        if(endY == imgPtr->size())
            endY--;
        int sum = 0;
        for(int y = startY; y <=endY; y++) {
            for(int x = startX; x <= endX; x++){
                sum += imgPtr->at(y)[x];
            }
        }
        return sum/((endY-startY+1)*(endX-startX+1));
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
       std::vector<std::vector<int>> smoothed = img;
       for(int y = 0; y < img.size(); y++) {
           for(int x = 0; x < img[0].size(); x++)
           smoothed[y][x] = averagePixel(x-1, x+1, y-1, y+1, &img);
       }
       return smoothed;
    }
};
