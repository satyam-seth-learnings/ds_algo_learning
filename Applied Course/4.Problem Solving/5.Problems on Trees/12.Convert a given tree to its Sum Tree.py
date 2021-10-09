import sys
class node: 

    def __init__(self, info): 
        self.info = info  
        self.left = None
        self.right = None 
        
def convertSumTree(root):
    if root==None:
        return 0
    
    oldval=root.info
    
    root.info=convertSumTree(root.left)+convertSumTree(root.right)
    
    return root.info+oldval

def inorder(ptr):
    if(ptr==None):
        return
    inorder(ptr.left)
    print(ptr.info)
    inorder(ptr.right)

if __name__=='__main__':
    root=None
    root=node(10)
    root.left=node(-2)
    root.right=node(6)
    root.left.left=node(8)
    root.left.right=node(-4)
    root.right.left=node(7)
    root.right.right=node(5)
    
    convertSumTree(root)
    
    inorder(root)
