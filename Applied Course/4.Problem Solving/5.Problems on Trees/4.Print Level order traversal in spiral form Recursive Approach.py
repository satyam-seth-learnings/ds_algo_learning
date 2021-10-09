import sys
class node: 

    def __init__(self, info): 
        self.info = info  
        self.left = None
        self.right = None 
    
def height(ptr):
    if ptr is None:
        return 0;
    
    lheight=height(ptr.left)
    rheight=height(ptr.right)
    if lheight>rheight:
        return 1+lheight
    else:
        return 1+rheight

def Levelorder(root,level,flag):
    if root is None:
        return
    if level==1:
        print(root.info)
    
    else: 
        if (flag is True):
            Levelorder(root.left,level-1,flag)
            Levelorder(root.right,level-1,flag)
        else:
            Levelorder(root.right,level-1,flag)
            Levelorder(root.left,level-1,flag)    

def printSpiral(root):
    h=height(root)
    flag=True
    for i in range(1,h+1):
        Levelorder(root,i,flag)
        flag=not flag
    
if __name__=='__main__':
    root=None
    root=node(10)
    root.left=node(20)
    root.right=node(30)
    root.left.left=node(40)
    root.left.right=node(50)
    root.right.left=node(60)
    root.right.right=node(70)
    printSpiral(root)
    
