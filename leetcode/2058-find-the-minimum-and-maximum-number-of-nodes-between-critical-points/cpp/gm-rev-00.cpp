// Runtime: 165ms
// Memory: 115.9MB
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int lastLastNodeValue = head->val;
        head = head->next;
        int lastNodeValue = head->val;
        head = head->next;
        int i = 1;

        std::vector<int> minMax = {100000,0};

        int firstCriticalPoint = -1;
        int previousCriticalPoint = -1;

        while(head) {
            if(lastLastNodeValue > lastNodeValue && head->val > lastNodeValue) {
                minMax[0] = std::min(minMax[0], i - previousCriticalPoint);
                previousCriticalPoint = i;
                if(firstCriticalPoint == -1) {
                    firstCriticalPoint = i;
                    minMax[0] = 100000;
                }
            } else if(lastLastNodeValue < lastNodeValue && head->val < lastNodeValue) {
                minMax[0] = std::min(minMax[0], i - previousCriticalPoint);
                previousCriticalPoint = i;
                if(firstCriticalPoint == -1) {
                    firstCriticalPoint = i;
                    minMax[0] = 100000;
                }
            }
            lastLastNodeValue = lastNodeValue;
            lastNodeValue = head->val;
            head = head->next;
            i++;
        }
        minMax[1] = previousCriticalPoint - firstCriticalPoint;

        if (firstCriticalPoint == previousCriticalPoint)
            minMax = {-1,-1};
        return minMax;
    }
};
