// Runtime 76ms
// Memory 39MB
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::unordered_map<string, int> ind_map;
        for(int i = 0; i < list1.size(); i++) {
            ind_map[list1[i]] = i + 1;
        }

        int least_index_sum = std::numeric_limits<int>::max();
        vector<string> ret;
        for(int j = 0; j < list2.size() && j < least_index_sum; j++) {
            if (ind_map[list2[j]]) {
                if(ind_map[list2[j]] + j < least_index_sum) {
                    least_index_sum = ind_map[list2[j]] + j;
                    ret = {};
                }
                if (ind_map[list2[j]] + j == least_index_sum) {
                    ret.push_back(list2[j]);
                }
            }
        }
        return ret;
    }
};
