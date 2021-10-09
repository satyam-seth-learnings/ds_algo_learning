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


def countNodes(root):
    if root==None:
        return 0
    return (1+countNodes(root.left)+countNodes(root.right))
    
if __name__=='__main__':
    root=None
    root=insert(root,10)
    root=insert(root,20)
    root=insert(root,5)
    root=insert(root,30)
    print(countNodes(root))
