// Runtime: 0ms
// Memory: 12.4MB
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        std::vector<int> ans;
        for(int i = 1; i <= n && i < 10; i++) {
            ans.push_back(i);
            for(int j = 0; i*10 + j <= n && j < 10; j++) {
                ans.push_back(i*10 + j);
                for(int k = 0; i*100 + j*10 + k <= n && k < 10; k++) {
                    ans.push_back(i*100 + j*10 + k);
                    for(int l = 0; i*1000 + j*100 + k*10 + l <= n && l < 10; l++) {
                        ans.push_back(i*1000 + j*100 + k*10 + l);
                        for(int m = 0; i*10000 + j*1000 + k*100 + l*10 + m <= n && m < 10; m++)
                            ans.push_back(i*10000 + j*1000 + k*100 + l*10 + m);
                    }
                }
            }
        }
        return ans;
    }
};
