// Runtime: 64ms
// Memory: 24.8MB
class KthLargest {
    std::vector<int> nums;
public:
    KthLargest(int k, vector<int>& nums) {
        std::sort(nums.begin(),nums.end(), std::greater());
        nums.push_back(-1001);
        (this->nums) = std::vector<int>(nums.begin(), nums.begin()+k);
    }

    int add(int val) {
        if (val > nums[0]) {
            for(int i = nums.size()-1; i > 0; i--)
                nums[i] = nums[i-1];
            nums[0] = val;
        } else if(val > nums[nums.size()-1]) {
            int begin = 0;
            int end = nums.size()-1;
            while(begin + 1 < end) {
                if(nums[(begin + end)/2] < val)
                    end = (begin + end)/2;
                else
                    begin = (begin + end)/2;
            }
            for(int i = nums.size()-1; i > end; i--)
                nums[i] = nums[i-1];
            nums[end] = val;
        }
        return nums[nums.size()-1];
    }
};
