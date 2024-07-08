// Runtime 19ms
// Memory: 8.3MB
class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k == 1)
            return n;
        std::set<int> friends;
        for(int i = 1; i <=n; i++)
            friends.insert(friends.end(),i);
        auto curr = friends.find(n);
        auto prev = std::prev(curr);

        while(friends.size() >1) {
            for(int counted = 0; counted < k; counted++) {
                prev = curr;
                curr = std::next(curr);
                if(curr == friends.end())
                    curr = friends.begin();
            }
            friends.erase((*curr));
            curr = prev;
        }

        return (*friends.begin());
    }
};
