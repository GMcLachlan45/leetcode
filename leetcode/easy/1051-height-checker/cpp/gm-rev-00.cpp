// Runtime: 2ms
// Memory: 10MB
class Solution {
public:
    int heightChecker(vector<int>& heights) {

        int expected[100];
        for(int i = 0; i < heights.size(); i++)
            expected[i] = heights[i];
        std::sort(expected, expected + heights.size());
        int count = 0;
        for(int i = 0; i < heights.size(); i++)
            if(heights[i] != expected[i])
               count++;

        return count;
    }
};
