// Runtime: 139ms
// Memory: 55.9MB
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        std::vector<int> arrivals(times.size());
        std::iota(arrivals.begin(), arrivals.end(), 0);

        std::vector<int> departures(times.size());
        std::iota(departures.begin(), departures.end(), 0);

        std::sort(arrivals.begin(), arrivals.end(), [&] (auto l, auto r) {
            return times[l][0] < times[r][0];
        });
        std::sort(departures.begin(), departures.end(), [&] (auto l, auto r) {
            return times[l][1] < times[r][1];
        });

        int nextArrival = 0;
        int nextDeparture = 0;

        std::vector<int> friendSeat(times.size());
        int nextChair = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> freeChairs;

        while(true) {
            if(times[arrivals[nextArrival]][0] < times[departures[nextDeparture]][1]) {
                if(arrivals[nextArrival] == targetFriend)
                    break;
                if(!freeChairs.empty()) {
                    friendSeat[arrivals[nextArrival]] = freeChairs.top();
                    freeChairs.pop();
                } else
                    friendSeat[arrivals[nextArrival]] = nextChair++;
                nextArrival++;
            } else if(friendSeat[departures[nextDeparture]] == nextChair - 1) {
                nextChair--;
                nextDeparture++;
            } else
                freeChairs.push(friendSeat[departures[nextDeparture++]]);
        }

        return (!freeChairs.empty()) ? freeChairs.top() : nextChair;
    }
};
