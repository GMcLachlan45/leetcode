// Runtime 134ms
// Memory 61.40MB
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;
        while(low < high){
            int middle = low + (high-low)/2;
            int count = 0;
            for(int i = 0; i < nums.size(); i++) {
                if (nums[i] <= middle)
                    count++;
            }
            if (count <= middle)
                low = middle + 1;
            else
                high = middle;
        }
        return low;
    }
};
