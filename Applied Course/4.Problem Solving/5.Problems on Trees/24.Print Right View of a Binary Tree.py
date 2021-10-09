# https://leetcode.com/problems/binary-tree-right-side-view/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return root
        queue=[]
        result=[]
        queue.append(root)
        while queue:
            n=len(queue)
            for i in range(1,n+1):
                current=queue[0]
                queue.pop(0)
                if i==n:
                    result.append(current.val)
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)
        return result