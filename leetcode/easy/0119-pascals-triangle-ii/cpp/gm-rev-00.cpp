// Runtime 0ms
// Memory 6.96MB
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> ret(rowIndex+1, 1);
        for(int i = 2; i <= rowIndex; i++) {
            int l = ret[0];
            int r = ret[1];
            for(int j = 1; j<(i+2)/2; j++) {
                ret[j] = l+r;
                ret[i-j] = l+r;
                l = r;
                r = ret[j+1];
            }
        }
        return ret;
    }
};
