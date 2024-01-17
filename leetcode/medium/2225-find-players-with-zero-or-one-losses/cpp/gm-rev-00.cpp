// Runtime: 605ms
// Memory: 182.82MB
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        std::map<int, int> mp;
        for(auto match: matches) {
            mp[match[0]];
            mp[match[1]]++;
        }

        std::vector<int> zero;
        std::vector<int> one;
        for(auto player: mp) {
            if(player.second == 0)
                zero.push_back(player.first);
            else if(player.second == 1)
                one.push_back(player.first);
        }
        return {zero, one};
    }
};
