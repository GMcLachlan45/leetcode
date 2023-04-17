// Runtime 156ms
// Memory 39.7MB
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int neg_count = 0;
        int smallest_neg = std::numeric_limits<int>::min();
        int smallest_pos = std::numeric_limits<int>::max();
        for (vector<int> x : matrix) {
            for (int y : x) {
                if (y < 1) {
                    neg_count++;
                    sum -= y;
                    if(y > smallest_neg)
                        smallest_neg = y;
                } else {
                    sum += y;
                    if(y < smallest_pos)
                        smallest_pos = y;
                }
            }
        }
        // if we can get a smaller number by flipping a + to -, we do it
        if(-1 * smallest_pos > smallest_neg)
            smallest_neg = -1 * smallest_pos;

        // if there's an odd number of negatives, we can't flip them all
        return (neg_count%2 == 1) ? sum + 2 * smallest_neg : sum;
    }
};
