// Runtime 3ms
// Memory 6.4MB
class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        std::unordered_set<int> visited = {};  
        while(!visited.count(n)) {
            visited.insert(n);
            n=0;
            while (num != 0) {
                n += (num % 10) * (num % 10);
                num /= 10;
            }
            num = n;
        }

        return visited.count(1);
    }
};
