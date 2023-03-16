// Runtime 2ms
// Memory 20.3MB

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n > flowerbed.size()/2 + 1)
            return false;
        if(flowerbed.size() == 1)
            return n == 0 || flowerbed[0] == 0;

        short int empty = 0;
        for(short int x = 0; x < flowerbed.size(); x++){
            if (x == 0) {
                if(!(flowerbed[x] || flowerbed[x+1])){
                    empty++;
                    x++;
                }
            } else if(x == flowerbed.size() - 1 ){
                if(!(flowerbed[x] || flowerbed[x-1])){
                    empty++;
                    x++;
                }
            } else if ( !(flowerbed[x-1] || flowerbed[x] || flowerbed[x+1])){
                empty++;
                x++;
            }
            if(empty >= n)
                return true;
        }

        return empty >= n;
    }
};
