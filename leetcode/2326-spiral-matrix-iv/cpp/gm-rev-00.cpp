// Runtime: 175ms
// Memory: 130.5MB
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        std::vector<std::vector<int>> ret(m, std::vector<int>(n, -1));

        std::pair<int,int> pos = {0,0};
        std::pair<int,int> deltaPos = {0,1};
        int steps = n;
        while(head) {
            ret[pos.first][pos.second] = head->val;
            head = head->next;
            if(!--steps) {
                steps = (deltaPos.second) ? --m : --n;
                deltaPos = {deltaPos.second, -deltaPos.first};
            }
            pos.first += deltaPos.first;
            pos.second += deltaPos.second;
        }
        return ret;
    }
};
