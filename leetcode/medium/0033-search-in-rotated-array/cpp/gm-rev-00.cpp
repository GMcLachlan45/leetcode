// Runtime: 0ms
// Memory: 15MB
class Solution {
    int findK(std::vector<int>& nums, int start, int end) {
        if(nums[end] >= nums[start])
            return -1;
        if(end == start + 1)
            return end;
        int k = findK(nums, start, (start+end)/2) + findK(nums, (start+end)/2 + 1, end) + 1;
        if(k == -1 && nums[(start+end)/2] > nums[(start + end)/2 + 1])
            k = (start+end)/2 + 1;
        return k;
    }

    int binarySearchWithOffset(std::vector<int>& nums, int start, int end, int k, int target) {
        if(start == end)
            return nums[(start + k) % nums.size()] == target ? ((start + k) % nums.size()) : -1;
        if(nums[((start + end)/2 + k) % nums.size()] >= target)
            return binarySearchWithOffset(nums, 0, (start + end)/2, k, target);
        else
            return binarySearchWithOffset(nums, (start + end)/2+1, end , k, target);
    }
public:
    int search(vector<int>& nums, int target) {
        int k = findK(nums, 0, nums.size()-1);
        if(k == -1)
            k = 0;
        return binarySearchWithOffset(nums, 0, nums.size()-1, k, target);
    }
};
