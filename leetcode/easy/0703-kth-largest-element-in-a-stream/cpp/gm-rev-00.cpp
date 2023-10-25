// Runtime: 238ms
// Memory: 19.9MB
class KthLargest {
int kth;
std::vector<int> v;
public:
    KthLargest(int k, vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        v = nums;
        kth = nums.size() - k;
    }
    
    int add(int val) {
        kth++;
        v.insert(std::lower_bound(v.begin(), v.end(), val), val);
        return v[kth];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
