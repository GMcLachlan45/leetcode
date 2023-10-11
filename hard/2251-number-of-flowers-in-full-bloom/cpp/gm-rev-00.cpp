// Runtime 233ms
// Memory 92.22MB

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        std::vector<int>flower_start;
        std::vector<int>flower_end;
        for(std::vector<int> flower: flowers) {
            flower_start.push_back(flower[0]);
            flower_end.push_back(flower[1]);
        }
        std::sort(flower_start.begin(), flower_start.end());
        std::sort(flower_end.begin(), flower_end.end());

        // Create new list of people with time and original pos
        std::vector<std::pair<int,int>> people_orig;
        for(int i = 0; i < people.size(); i++)
            people_orig.push_back({people[i], i});

        std::sort(people_orig.begin(), people_orig.end(),
            [] (std::pair<int,int> a, std::pair<int,int> b) {
                return a.first < b.first;
            }
        );
        std::vector<int> ret(people.size());

        int start_ptr = 0;
        int end_ptr = 0;
        int flowers_in_bloom = 0;
        for(std::pair<int,int> person: people_orig) {
            while(start_ptr < flower_start.size() && flower_start[start_ptr] <= person.first){
                flowers_in_bloom++;
                start_ptr++;
            }
            while(end_ptr < flower_end.size() && flower_end[end_ptr]< person.first) {
                flowers_in_bloom--;
                end_ptr++;
            }
            ret[person.second] = flowers_in_bloom;
        }

        return ret;
    }

};
