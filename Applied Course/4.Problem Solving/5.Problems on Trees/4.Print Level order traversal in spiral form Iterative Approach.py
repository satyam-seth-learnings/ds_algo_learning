# https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Logic-1
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        currentLevel,nextLevel=[],[]
        currentLevel.append(root)
        ltr=True
        result,temp=[],[]
        while currentLevel:
            current=currentLevel.pop(-1)
            temp.append(current.val)
            if ltr:
                if current.left:
                    nextLevel.append(current.left)
                if current.right:
                    nextLevel.append(current.right)
            else:
                if current.right:
                    nextLevel.append(current.right)
                if current.left:
                    nextLevel.append(current.left)
            if len(currentLevel)==0:
                result.append(temp)
                ltr=not ltr
                currentLevel,nextLevel=nextLevel,currentLevel
                temp=[]
        return result
# Logic-2
import sys
class Node: 

    def __init__(self, info): 
        self.info = info  
        self.left = None
        self.right = None 
class node: 

    def __init__(self, info): 
        self.info = info  
        self.next = None 


class Stack: 

    def __init__(self): 
        self.top = None
        
    
    def isEmpty(self):
        if self.top is None:
            return True
        return False
    
    def push(self,data):
        self.temp=node(data)
        if self.temp is None:
            print("Stack overflow")
            return
        self.temp.next=self.top
        self.top=self.temp
    
    def pop(self):
        if self.isEmpty():
            print("Stack Underflow")
            sys.exit(0)
        d=self.top.info
        self.top=self.top.next    
        return d
    
    def peek(self):
        if self.isEmpty():
            print("Stack Underflow")
            sys.exit(0)
        d=self.top.info
        return d
    def display(self):
        if self.isEmpty():
            print("Stack Underflow")
            sys.exit(0)
        self.p=self.top
        while self.p is not None:
            print(self.p.info)
            self.p=self.p.next

def printSpiralRecursive(root):
    stack1=Stack()
    stack2=Stack()
    stack1.push(root)
    
    while (stack1.isEmpty() is not True) or (stack2.isEmpty() is not True):
        while(stack1.isEmpty() is not True):
            temp=stack1.pop()
            print(temp.info)
            if(temp.right is not None):
                stack2.push(temp.right)
            if(temp.left is not None):
                stack2.push(temp.left)
        while(stack2.isEmpty() is not True):
            temp=stack2.pop()
            print(temp.info)
            if(temp.left is not None):
                stack1.push(temp.left)
            if(temp.right is not None):
                stack1.push(temp.right)

if __name__=='__main__':
    root=None
    root=Node(10)
    root.left=Node(20)
    root.right=Node(30)
    root.left.left=Node(40)
    root.left.right=Node(50)
    root.right.left=Node(60)
    root.right.right=Node(70)
    printSpiralRecursive(root)

