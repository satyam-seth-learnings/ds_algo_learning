# https://leetcode.com/problems/validate-binary-search-tree/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Logic-1
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def check(root,lower,upper):
            if not root:
                return True
            val=root.val
            if val<=lower or val>=upper:
                return False
            if not check(root.left,lower,val):
                return False
            if not check(root.right,val,upper):
                return False
            return True
        lower=float('-inf')
        upper=float('+inf')
        return check(root,lower,upper)
# Logic-2
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root:
            return True
        stack=[(root,float('-inf'),float('+inf'))]
        while stack:
            root,lower,upper=stack.pop()
            if not root:
                continue
            val=root.val
            if val<=lower or val>=upper:
                return False
            stack.append((root.right,val,upper))
            stack.append((root.left,lower,val))
        return True