// Runtime: 0ms
// Memory: 8.23MB
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        std::vector<std::string> ret;
        int i = 1;
        for(int x: target) {
            while(i != x) {
                ret.push_back("Push");
                ret.push_back("Pop");
                i++;
            }
            i++;
            ret.push_back("Push");
        }
        return ret;
    }
};
