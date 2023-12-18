// Runtime: 383ms
// Memory: 162.26MB
class FoodRatings {
    struct comp {
        bool operator() (const std::pair<int, std::string>& l, const std::pair<int, std::string>& r) const {
            if(l.first == r.first)
                return l.second > r.second;
            return l.first < r.first;
        }
    };

    std::unordered_map<std::string, std::set<std::pair<int,std::string>, comp>> cuisine;
    std::unordered_map<std::string, std::pair<std::string, std::pair<int, std::string>>> foodPtr;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            std::pair<int, std::string> food = {ratings[i], foods[i]};
            foodPtr[foods[i]] = {cuisines[i], food};
            cuisine[cuisines[i]].insert(food);
        }
    }

    void changeRating(string food, int newRating) {
        auto f = foodPtr[food];
        cuisine[f.first].extract(f.second);
        cuisine[f.first].insert({newRating, food});
        foodPtr[food].second.first = newRating;
    }

    string highestRated(string c) {
        return (*cuisine[c].rbegin()).second;
    }
};
