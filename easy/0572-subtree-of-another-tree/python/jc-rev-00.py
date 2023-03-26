# runtime: 54ms
# memory: 14.6MB
class Solution(object):
    # why not use python string stuff, it's kinda based as hell
    # use "r" prefix before node.val to denote that it's the root of a subtree
    def stringify(self, node):
        if node is not None:
            return "r{}{}{}".format(node.val, self.stringify(node.left), self.stringify(node.right))
        return None
 
    def isSubtree(self, root, subRoot):
        """
        :type root: TreeNode
        :type subRoot: TreeNode
        :rtype: bool
        """
        s1 = self.stringify(root)
        s2 = self.stringify(subRoot)
        return s2 in s1