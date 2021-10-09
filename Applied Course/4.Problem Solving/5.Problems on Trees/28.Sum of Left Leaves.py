# https://leetcode.com/problems/sum-of-left-leaves/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        result=0
        if not root:
            return result
        if root.left and not root.left.left and not root.left.right:
            result+=root.left.val
        return result+self.sumOfLeftLeaves(root.left)+self.sumOfLeftLeaves(root.right)