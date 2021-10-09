# https://leetcode.com/problems/kth-smallest-element-in-a-bst/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Logic-1
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def inorder(root):
            return inorder(root.left)+[root.val]+inorder(root.right) if root else []
        lst=inorder(root)
        return lst[k-1]
# Logic-2
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack=[]
        while True:
            while root:
                stack.append(root)
                root=root.left
            root=stack.pop()
            k-=1
            if k==0:
                return root.val
            root=root.right