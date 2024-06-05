// Runtime: 270ms
// Memory: 93.6MB
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        std::vector<std::pair<float,std::pair<int,int>>> fracs;

        for(int i = 0; i < arr.size(); i++) {
            for(int j = arr.size()-1; j > i; j--) {
                fracs.push_back({(float) arr[i]/arr[j], {arr[i],arr[j]}});
            }
        }
        std::sort(fracs.begin(), fracs.end(), [] (const auto& a, const auto& b) { return a.first < b.first;});
        return {fracs[k-1].second.first, fracs[k-1].second.second};
    }
};
xk
