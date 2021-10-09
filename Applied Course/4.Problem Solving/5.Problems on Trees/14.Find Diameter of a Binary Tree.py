import sys
ans=-sys.maxsize -1
class node: 

    def __init__(self, info): 
        self.info = info  
        self.left = None
        self.right = None 

def height(ptr):
    global ans
    if ptr is None:
        return 0
    
    lheight=height(ptr.left)
    rheight=height(ptr.right)
    ans=max(ans,1+lheight+rheight)
    if lheight>rheight:
        return 1+lheight
    else:
        return 1+rheight
        
def getDiameter(root):
    if root is None:
        return 0
    h=height(root)
    
if __name__=='__main__':
    root=None
    root=node(10)
    root.left=node(20)
    root.right=node(30)
    root.left.left=node(40)
    root.left.right=node(50)
    getDiameter(root)
    print(ans)
