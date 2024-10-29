// Runtime: 234ms
// Memory: 164.83MB
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        std::unordered_set<int> checked;

        // checks if num is next in list's sequence
        std::unordered_map<int, std::pair<int,int>> next;
        //checks if num is at front of list's sequence
        std::unordered_map<int, std::pair<int,int>> prev;

        int maxCount = -1;
        for(int num : nums) {
            if(checked.count(num))
                continue;
            checked.insert(num);

            int sqrt_num = 0;
            if(std::sqrt(num) == (int) std::sqrt(num))
                sqrt_num = std::sqrt(num);
            int num_squared = (num < 46341) ? num * num: 0;

            if(sqrt_num && num_squared && next.find(num_squared) != next.end() && prev.find(sqrt_num) != prev.end()) {
                int total = next[num_squared].first + 1 + prev[sqrt_num].first;

                prev[next[num_squared].second].first = total;
                prev[next[num_squared].second].second = next[num_squared].second;
                next[prev[sqrt_num].second].first = total;
                next[prev[sqrt_num].second].second = prev[sqrt_num].second;

                maxCount = (maxCount < total) ? total : maxCount;
            } else if(num_squared && next.find(num_squared) != next.end() ) {
                prev[next[num_squared].second].first++;
                prev[next[num_squared].second].second = num;

                next[num] = next[num_squared];
                next[num].first++;
                maxCount = (maxCount < next[num].first) ? next[num].first : maxCount;
            } else if(sqrt_num && prev.find(sqrt_num) != prev.end() ) {
                next[prev[sqrt_num].second].first++;
                next[prev[sqrt_num].second].second = num;

                prev[num] = prev[sqrt_num];
                prev[num].first++;
                maxCount = (maxCount < prev[num].first) ? prev[num].first : maxCount;
            } else {
                next[num] = {1, num};
                prev[num] = {1, num};
            }
        }
        return maxCount;
    }
};
