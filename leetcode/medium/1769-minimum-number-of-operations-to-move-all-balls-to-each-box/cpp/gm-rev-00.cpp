// Runtime: 2ms
// Memory: 12.5MB
class Solution {
public:
    vector<int> minOperations(string boxes) {
        std::vector<int> forward(boxes.size());
        int balls_passed = boxes[0]-'0';
        // Forward Pass
        for(int i = 1; i < boxes.size(); i++) {
            forward[i] = forward[i-1] + balls_passed;
            balls_passed += boxes[i]-'0';
        }
        std::vector<int> backward(boxes.size());
        balls_passed = boxes[boxes.size() - 1]-'0';
        // Backward Pass
        for(int i = boxes.size() - 2; i >= 0; i--) {
            backward[i] = backward[i+1] + balls_passed;
            balls_passed += boxes[i]-'0';
        }

        // combine both these passes into forward
        for(int i = 0; i < boxes.size(); i++)
            forward[i] += backward[i];

        return forward;
    }
};
