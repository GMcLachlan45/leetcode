// Runtime 61ms
// Memory 27.71MB
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        long count = 0;
        int max = arr[arr.size()-1];
        std::unordered_map<int, long> trees;
        for(int x: arr) {
            trees[x] = 1;
        }
        for(int i = 0; i < arr.size(); i++) {
            count = (count + trees[arr[i]])%1000000007;
            for(int j = 0; j < i; j++){
                if((long) arr[i] * arr[j] > max)
                    break;
                int mult = arr[i] * arr[j];
                if(trees[mult]) {
                    trees[mult] += 2 * trees[arr[i]] * trees[arr[j]];
                }
            }
            if((long) arr[i] * arr[i] <= max && trees[arr[i] * arr[i]])
                trees[arr[i] * arr[i]] += trees[arr[i]] * trees[arr[i]];
        }
        return (int) count;
    }
};
