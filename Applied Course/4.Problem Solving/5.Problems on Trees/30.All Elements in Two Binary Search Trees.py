# https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Logic-1
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def inorder(root):
            if root:
                return inorder(root.left)+[root.val]+inorder(root.right)
            else:
                return []
        tree1=inorder(root1)
        tree2=inorder(root2)
        result=[]
        i,j=0,0
        while i<len(tree1) and j<len(tree2):
            if tree1[i]<tree2[j]:
                result.append(tree1[i])
                i+=1
            else:
                result.append(tree2[j])
                j+=1
        if i<len(tree1):
            result+=tree1[i:]
        if j<len(tree2):
            result+=tree2[j:]
        return result
# Logic-2
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        stack1,stack2,result=[],[],[]
        while root1 or root2 or stack1 or stack2:
            while root1:
                stack1.append(root1)
                root1=root1.left
            while root2:
                stack2.append(root2)
                root2=root2.left
            if not stack2 or stack1 and stack1[-1].val<=stack2[-1].val:
                root1=stack1.pop()
                result.append(root1.val)
                root1=root1.right
            else:
                root2=stack2.pop()
                result.append(root2.val)
                root2=root2.right
        return result