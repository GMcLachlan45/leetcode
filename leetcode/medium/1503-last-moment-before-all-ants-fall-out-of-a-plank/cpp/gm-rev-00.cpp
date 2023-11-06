// Runtime: 17ms
// Memory: 23.1MB
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size() == 0)
            return n- *std::min_element(std::begin(right), std::end(right));
        if(right.size() == 0)
            return *std::max_element(std::begin(left), std::end(left));
        return std::max(*std::max_element(std::begin(left), std::end(left)), n-*std::min_element(std::begin(right), std::end(right)));
    }
};
