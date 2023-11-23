// Runtime: 38ms
// Memory: 26.24MB
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        std::vector<bool> answer;
        for(int m = 0; m < l.size(); m++) {
            std::vector<int> cp(r[m]-l[m]+1);
            std::copy(nums.begin()+l[m], nums.begin()+ r[m]+1, cp.begin());
            std::sort(cp.begin(), cp.end());

            int diff = cp[1] - cp[0];
            bool holds = true;
            for(int i = 1; holds && i < cp.size(); i++)
                holds = (cp[i]-cp[i-1] == diff);
            answer.push_back(holds);
        }
        return answer;
    }
};
