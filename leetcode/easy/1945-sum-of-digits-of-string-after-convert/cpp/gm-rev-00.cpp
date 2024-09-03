// Runtime: 0ms
// Memory: 8.2MB
class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(char c : s)
            sum += (c-'a' + 1)/10 + (c-'a' + 1) % 10;
        while(sum >= 9 && --k) {
            int nextSum = 0;
            for(char c : std::to_string(sum))
                nextSum += c-'0';
            sum = nextSum;
        }
        return sum;
    }
};
