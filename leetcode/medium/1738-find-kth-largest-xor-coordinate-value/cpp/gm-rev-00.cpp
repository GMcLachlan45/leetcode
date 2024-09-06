// Runtime 368ms
// Memory 113.55MB
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        std::vector<int> kLargest;
        for(int i = 0; i <matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                int next = 0 ^ matrix[i][j];
                if(i > 0)
                    next ^= matrix[i-1][j];
                if(j > 0)
                    next ^= matrix[i][j-1];
                if(i > 0 && j > 0)
                    next ^= matrix[i-1][j-1];
                matrix[i][j] = next;
                kLargest.push_back(next);
            }
        }
        std::sort(kLargest.begin(), kLargest.end());
        return kLargest[kLargest.size() - k];
    }
};
