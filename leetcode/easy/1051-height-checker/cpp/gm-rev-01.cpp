// Runtime: 0ms
// Memory: 9.9 MB
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::map<int,int> height_count;
        for(int x : heights)
            height_count[x]++;

        int count = 0;
        int ptr = 0;
        for(auto x : height_count) {
            while(x.second) {
                if(heights[ptr] != x.first)
                    count++;
                x.second--;
                ptr++;
            }
        }

        return count;
    }
};
