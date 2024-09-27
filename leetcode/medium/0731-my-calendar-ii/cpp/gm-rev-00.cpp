// Runtime: 74ms
// Memory: 39.42MB
class MyCalendarTwo {
    std::map<int,int> cal;
public:
    MyCalendarTwo() {
        this->cal = {{0,0}, {1000000000, 0}};
    }

    bool book(int start, int end) {
        auto it = cal.upper_bound(start);
        it--;
        for(auto check = it; check->first < end; check++)
            if(check->second == 2)
                return false;

        if(cal.find(start) == cal.end()){
            cal[start] = it->second;
            it++;
        }

        for(auto incr = it; incr->first < end; incr++)
            incr->second++;

        if(cal.find(end) == cal.end()){
            it = cal.upper_bound(end);
            it--;
            cal[end] = it->second-1;
        }
        return true;
    }
};
