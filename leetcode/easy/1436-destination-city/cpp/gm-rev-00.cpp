// Runtime: 15ms
// Memory: 11.86MB
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        std::unordered_set<std::string> candidates;
        std::unordered_set<std::string> outgoing;
        for(std::vector<std::string> path : paths) {
            if(!outgoing.count(path[1]))
                candidates.insert(path[1]);
            outgoing.insert(path[0]);
            if(candidates.count(path[0]))
                candidates.erase(path[0]);
        }
        return *candidates.begin();
    }
};
