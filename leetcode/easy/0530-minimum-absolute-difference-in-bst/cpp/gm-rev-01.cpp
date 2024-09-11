// Runtime: 15ms
// Memory: 25.1MB
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        std::vector<int> nums;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            if(q.front()){
                nums.push_back(q.front()->val);
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }

        std::sort(nums.begin(), nums.end());
        int ans = 100000;
        for(int i = 1; i < nums.size(); i++)
            if(ans > nums[i] - nums[i-1])
                ans = nums[i] - nums[i-1];
        return ans;
    }
};
