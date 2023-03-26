# Runtime:      42 ms (96.96%)
# Memory usage: 14.7 MB (99.95%)
class Solution:
    depthList = []

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root is None or root.left is None and root.right is None:
            return True
        leftDepth = 0
        rightDepth = 0
        leftQueue = []
        if root.left is not None:
            leftDepth += 1
            leftQueue.append(root.left)
        rightQueue = []
        if root.right is not None:
            rightDepth += 1
            rightQueue.append(root.right)

        while True:
            leftDepthBefore = leftDepth
            rightDepthBefore = rightDepth
            newLeftQueue = []
            for node in leftQueue:
                if node.left is not None:
                    newLeftQueue.append(node.left)
                if node.right is not None:
                    newLeftQueue.append(node.right)
            leftQueue = newLeftQueue
            if len(leftQueue) > 0:
                leftDepth += 1

            newRightQueue = []
            for node in rightQueue:
                if node.left is not None:
                    newRightQueue.append(node.left)
                if node.right is not None:
                    newRightQueue.append(node.right)
            rightQueue = newRightQueue
            if len(rightQueue) > 0:
                rightDepth += 1

            # niter += 1
            # print("iter:", niter, "leftDepth:", leftDepth, "rightDepth:", rightDepth)
            if abs(rightDepth - leftDepth) > 1:
                return False
            elif leftDepth == leftDepthBefore and rightDepth == rightDepthBefore:
                return self.isBalanced(root.left) and self.isBalanced(root.right)
