// Runtime: 83ms
// Memory: 44.5MB
class MyCalendar {
    std::map<int,bool> calendar;
public:
    MyCalendar() {calendar = {{0, false}};}

    bool book(int start, int end) {
        auto boundary = calendar.upper_bound(start);
        boundary--;
        if(!boundary->second) {
            boundary++;
            if(boundary == calendar.end() || end < boundary->first) {
                calendar[start] = true;
                calendar[end] = false;
                return true;
            } else if (end == boundary->first) {
                calendar[start] = true;
                return true;
            }
        }
        return false;
    }
};
