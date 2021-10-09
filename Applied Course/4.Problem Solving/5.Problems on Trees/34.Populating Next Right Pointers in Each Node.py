# https://leetcode.com/problems/populating-next-right-pointers-in-each-node
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        queue=[root,None]
        while queue:
            current=queue.pop(0)
            if current==None:
                if queue:
                    queue.append(None)
            else:
                current.next=queue[0]
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)
        return root