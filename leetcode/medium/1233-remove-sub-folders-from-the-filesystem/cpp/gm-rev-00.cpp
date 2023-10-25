// Runtime 169ms
// Memory 47.93MB
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        std::sort(folder.begin(), folder.end());
        std::string ref = "*";
        std::vector<std::string> ret;
        for(std::string x: folder) {
            if(x.find(ref) != 0) {
                ret.push_back(x);
                ref = x + "/";
            }
        }
        return ret;
    }
};
