# runtime: 45ms, my computer's bad
# memory: 21MB
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """

        count = 0
        stk = []
        curNode = root
        while curNode or stk:
            while curNode: # go all the way left
                stk.append(curNode)
                curNode = curNode.left
            # at node
            curNode = stk.pop()
            count += 1
            if count == k:
                return curNode.val
            curNode = curNode.right # go right if possible
