//1 ms
//42.2MB
class Solution {
    public boolean isCompleteTree(TreeNode root) {
        if(root == null)
            return true;
        Queue<TreeNode> q = new LinkedList<>();
        boolean f = false;
        q.add(root);
        while(!q.isEmpty()){
            TreeNode n = q.remove();
            if(f && n.left != null)
                return false;
            if(n.left == null && n.right != null)
                return false;
            if(n.left != null)
                q.add(n.left);
            else
                f = true;
            if(n.right != null)
                q.add(n.right);
            else
                f = true;
        }
        return true;
    }
}
