// Runtime: 44ms
// Memory: 25.3MB
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int group_count = 0;
        int overlaps = 0;
        std::unordered_map<int, std::pair<std::vector<int>,std::vector<int>>> group;
        std::unordered_map<int,int> row;
        std::unordered_map<int,int> col;

        for(std::vector<int> stone : stones) {
            if(row[stone[0]] == 0 && col[stone[1]] == 0) {
                group_count++;

                row[stone[0]] = group_count;
                col[stone[1]] = group_count;
                group[group_count].first.push_back(stone[0]);
                group[group_count].second.push_back(stone[1]);
            } else if(row[stone[0]] == 0 && col[stone[1]] != 0) {
                row[stone[0]] =  col[stone[1]];
                group[col[stone[1]]].first.push_back(stone[0]);
            } else if(row[stone[0]] != 0 && col[stone[1]] == 0) {
                col[stone[1]] =  row[stone[0]];
                group[row[stone[0]]].second.push_back(stone[1]);
            } else if(row[stone[0]] != 0 && col[stone[1]] != 0 && row[stone[0]] != col[stone[1]]) {
                int bigger_group = std::max(row[stone[0]], col[stone[1]]);
                int smaller_group = std::min(row[stone[0]], col[stone[1]]);

                for(int row_num : group[bigger_group].first) {
                    row[row_num] = smaller_group;
                    group[smaller_group].first.push_back(row_num);
                }
                for(int col_num : group[bigger_group].second) {
                    col[col_num] = smaller_group;
                    group[smaller_group].second.push_back(col_num);
                }
                group[bigger_group] = {};

                overlaps++;
            }
        }

        return  stones.size() - (group_count - overlaps);
    }
};
