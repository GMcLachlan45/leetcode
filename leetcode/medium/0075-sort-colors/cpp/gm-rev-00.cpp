// Runtime: 5ms
// Memory: 9.86MB
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 1;
        int white = 1;
        int blue = 1;
        for(int i = 0; i < nums.size(); i++) {
            switch (nums[i]) {
                case 0: red++; break;
                case 1: white++; break;
                case 2: blue++; break;
            }
        }
        int ptr = 0;
        while(--red)
            nums[ptr++]= 0;
        while(--white)
            nums[ptr++]= 1;
        while(--blue)
            nums[ptr++]= 2;
    }
};
