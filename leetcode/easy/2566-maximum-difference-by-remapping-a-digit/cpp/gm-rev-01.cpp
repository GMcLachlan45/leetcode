// Runtime 4ms
// Memory 6MB
class Solution {
public:
    int minMaxDifference(int num) {
        string max = std::to_string(num);
        string min = max;
        std::replace(min.begin(), min.end(), (char) min[0], '0');
        for(char x : max) {
            if(x != '9') {
                std::replace(max.begin(), max.end(), x, '9');
                break;
            }
        }
        return std::stoi(max) - std::stoi(min);
    }
};