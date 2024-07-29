class Solution {
public:
    int numTeams(vector<int>& rating) {
        std::vector<std::pair<int,int>> relativeRating(rating.size());

        for(int i = 0; i < rating.size(); i++) {
            for(int j = i + 1; j < rating.size(); j++ ) {
                if(rating[j] < rating[i])
                    relativeRating[i].first++;
                else if(rating[j] > rating[i])
                    relativeRating[i].second++;
            }
        }

        int teams = 0;
        for(int i = 0; i < rating.size(); i++) {
            for(int j = i + 1; j < rating.size(); j++ ) {
                if(rating[i] < rating[j])
                    teams += relativeRating[j].second;
                else if(rating[i] > rating[j])
                    teams += relativeRating[j].first;
            }
        }

        return teams;

    }
};
