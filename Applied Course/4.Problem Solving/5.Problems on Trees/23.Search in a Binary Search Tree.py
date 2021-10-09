# https://leetcode.com/problems/search-in-a-binary-search-tree/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Logic-1
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root or root.val==val:
            return root
        if root.val>val:
            return self.searchBST(root.left,val)
        if root.val<val:
            return self.searchBST(root.right,val)
# Logic-2
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        while root!=None and root.val!=val:
            if root.val>val:
                root=root.left
            else:
                root=root.right
        return root