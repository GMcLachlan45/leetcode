// Runtime: 183ms
// Memory: 86.4MB
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int current_time = 0;
        long total_waiting = 0;
        for(std::vector<int> order : customers) {
            if(current_time < order[0])
                current_time = order[0];
            current_time += order[1];
            total_waiting += current_time  - order[0];
        }
        return ( ((double) total_waiting) / customers.size() );
    }
};
