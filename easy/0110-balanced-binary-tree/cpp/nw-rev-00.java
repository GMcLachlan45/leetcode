// Runtime 1ms
// Memory 42.7MB
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int checkBalance(TreeNode root){
        if(root == null)
            return 1;

        int leftBalanced = checkBalance(root.left);

        if(leftBalanced < 1)
            return 0;

        int rightBalanced = checkBalance(root.right);
        if(rightBalanced < 1)
            return 0;

        if(Math.abs(leftBalanced - rightBalanced) > 1){
            return 0;
        } else {
            return Math.max(leftBalanced, rightBalanced) + 1;
        }
    }

    public boolean isBalanced(TreeNode root) {
        if(checkBalance(root) > 0)
            return true;
        else
            return false;
    }
}