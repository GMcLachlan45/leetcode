// Runtime: 13ms
// Memory: 13.88MB
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        std::vector<int> colCount(n);
        std::vector<int> rowCount(m);
        std::vector<std::pair<int,int>> dots;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j]) {
                    dots.push_back({i,j});
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        int sum = 0;
        for(std::pair<int,int> dot: dots) {
            if(rowCount[dot.first] ==1 && colCount[dot.second] == 1)
                sum++;
        }
        return sum;
    }
};
