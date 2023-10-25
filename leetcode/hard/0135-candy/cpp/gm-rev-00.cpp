// Runtime 20ms
// Memory 18.03MB
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() <= 1)
            return 1;

        int candyCount = 0;
        std::vector<int> candies(ratings.size(), 1);
        for(int i = candies.size() - 2; i > 0; i--) {
            if(ratings[i]>ratings[i+1])
                candies[i] = candies[i+1] + 1;
        }
        candies[0] = (ratings[0] > ratings[1]) ? candies[1] + 1: 1;
        for(int i = 0; i < ratings.size(); i++) {
            if(i-1 >= 0 && ratings[i-1] < ratings[i]) {
                candies[i] = candies[i-1] + 1;
            }
            if(i+1 < ratings.size() && ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
                candies[i] = candies[i+1] + 1;
            }
            candyCount +=candies[i];
        }

        return candyCount;
    }
};
