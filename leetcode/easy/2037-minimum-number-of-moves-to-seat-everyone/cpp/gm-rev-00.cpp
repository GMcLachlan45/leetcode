// Runtime: 6ms
// Memory: 20.8MB
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int positions[101];

        int current_difference = 0;
        int ret = 0;
        for(int seat : seats)
            positions[seat]++;
        for(int student : students)
            positions[student]--;
        for(int i = 0; i <=100; i++) {
            ret += std::abs(current_difference);
            current_difference += positions[i];
        }
        return ret;
    }
};
