import sys
class node: 

    def __init__(self, info): 
        self.info = info  
        self.left = None
        self.right = None 

def checkChildSum(root):
    ldata=rdata=0
    if(root==None or (root.left==None and root.right==None)):
        return True
    else:
        if(root.left!=None):
            ldata=root.left.info
        if(root.right!=None):
            rdata=root.right.info
        
        if(root.info==ldata+rdata and checkChildSum(root.left) and checkChildSum(root.right)):
            return True
        else:
            return False

if __name__=='__main__':
    root=node(15)
    root.left=node(10)
    root.right=node(5)
    inorder(root)
    if(checkChildSum(root) is True):
        print("children sum property")
    else:
        print("not satisfy children sum property")
