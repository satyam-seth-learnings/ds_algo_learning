import sys
class node: 

    def __init__(self, info): 
        self.info = info  
        self.left = None
        self.right = None 
    
def insert(ptr,key):
    if(ptr is None):
        ptr=node(key)
    elif(key<=ptr.info):
        ptr.left=insert(ptr.left,key)
    elif(key>ptr.info):
        ptr.right=insert(ptr.right,key)
    return ptr

def printAncestors(root,target):
    if root is None:
        return False
    
    if root.info==target:
        return True
    
    if(printAncestors(root.left,target) or printAncestors(root.right,target)):
        print(root.info)
        return 1
    return 0

if __name__=='__main__':
    root=None
    root=insert(root,10)
    root=insert(root,5)
    root=insert(root,15)
    root=insert(root,30)
    printAncestors(root,30)
