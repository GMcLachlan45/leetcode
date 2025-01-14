// Runtime: 0ms
// Memory: 85.5MB
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        bool passed[51] = {};
        std::vector<int> ans(A.size());
        int count = 0;
        for(int i = 0; i < A.size(); i++) {
            if(passed[A[i]])
                count++;
            passed[A[i]] = true;
            if(passed[B[i]])
                count++;
            passed[B[i]] = true;
            ans[i] = count;
        }
        return ans;
    }
};
