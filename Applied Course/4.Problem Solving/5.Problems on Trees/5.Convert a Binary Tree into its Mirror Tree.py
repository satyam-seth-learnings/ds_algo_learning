# https://leetcode.com/problems/invert-binary-tree/
# Logic-1
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root==None:
            return None
        else:
            self.invertTree(root.left)
            self.invertTree(root.right)
            root.left,root.right=root.right,root.left
            return root
# Logic-2
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Function to perform preorder traversal on a given binary tree
def preorder(root):
 
    if root is None:
        return
 
    print(root.data, end=' ')
    preorder(root.left)
    preorder(root.right)
 
 
# Utility function to swap left subtree with right subtree
def swap(root):
 
    if root is None:
        return
 
    temp = root.left
    root.left = root.right
    root.right = temp
 
 
# Function to convert a given binary tree into its mirror
def convertToMirror(root):
 
    # base case: if the tree is empty
    if root is None:
        return
 
    # convert left subtree
    convertToMirror(root.left)
 
    # convert right subtree
    convertToMirror(root.right)
 
    # swap left subtree with right subtree
    swap(root)
 
 
if __name__ == '__main__':
 
    ''' Construct the following tree
              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
    '''
 
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
 
    convertToMirror(root)
    preorder(root)