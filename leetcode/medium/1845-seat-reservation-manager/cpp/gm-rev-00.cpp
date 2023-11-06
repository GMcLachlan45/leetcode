// Runtime: 2354ms
// Memory: 442.5MB
class SeatManager {
    std::stack<int> seats;
public:
    SeatManager(int n) {
        while(n>0) {
            seats.push(n--);
        }
    }

    int reserve() {
        int ret = seats.top();
        seats.pop();
        return ret;
    }

    void unreserve(int seatNumber) {
        std::stack<int> lowerSeats;
        while(!seats.empty() && seatNumber > seats.top()) {
            lowerSeats.push(seats.top());
            seats.pop();
        }
        seats.push(seatNumber);
        while(!lowerSeats.empty()) {
            seats.push(lowerSeats.top());
            lowerSeats.pop();
        }
    }
};
