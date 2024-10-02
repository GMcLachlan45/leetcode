// Runtime: 53ms
// Memory: 34.7MB
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        std::vector<int> order(arr.size());
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&] (auto l, auto r) {
            return arr[l] < arr[r];
        });

        int rank = 1;
        int i = 0;
        while(i < order.size()) {
            while(i < order.size()-1 && arr[order[i]] == arr[order[i+1]])
                arr[order[i++]] = rank;
            arr[order[i++]] = rank++;
        }
        return arr;
    }
};
