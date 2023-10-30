// Runtime: 10ms
// Memory: 10.4MB
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), [](int a, int b) {
            if(std::bitset<14>(a).count() == std::bitset<14>(b).count())
                return a < b;
            return std::bitset<14>(a).count() < std::bitset<14>(b).count();
        });PP
        return arr;
    }
};
