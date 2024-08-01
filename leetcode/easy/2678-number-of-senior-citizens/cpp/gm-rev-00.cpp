// Runtime: 3ms
// Memory: 17.5MB
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(int i = 0; i < details.size(); i++)
            count +=  10 * details[i][11] + details[i][12] > 588;
        return count;
    }
};
