import sys
class node: 

    def __init__(self, info): 
        self.info = info  
        self.left = None
        self.right = None 
        
def leaf_nodes(ptr):
    if ptr is None:
        return 0
    if ptr.left is None and ptr.right is None:
        print(ptr.info)
        return 1
    else:
        return leaf_nodes(ptr.left)+leaf_nodes(ptr.right)

def insert(ptr,key):
    if(ptr is None):
        ptr=node(value)
    elif(key<=ptr.info):
        ptr.left=insert(ptr.left,key)
    elif(key>ptr.info):
        ptr.right=insert(ptr.right,key)
    return ptr

def size(ptr):
    if ptr is None:
        return 0;
    return 1+size(ptr.left)+size(ptr.right)

def minht(ptr):
    if ptr is None:
        return 0;
    
    lheight=minht(ptr.left)
    rheight=minht(ptr.right)
    
    if(lheight==0 and rheight!=0):
        return 1 + rheight
    if(rheight==0 and lheight!=0):
        return 1 + lheight;
    
    if lheight<rheight:
        return 1+lheight
    else:
        return 1+rheight
    
def Destroy(ptr):
    if(ptr is not None):
        Destroy(ptr.left)
        Destroy(ptr.right)
        ptr=None
        
    return None

def displayAncestors(ptr,item):
    if ptr is None or ptr.info==item:
        return
    
    if(ptr.info>item):
        displayAncestors(ptr.left,item)
    else:
        displayAncestors(ptr.right,item)
    print(ptr.info)
    
def displayPaths(ptr,paths,n):
    if ptr is None:
        return
    paths[n]=ptr.info
    n+=1
    if(ptr.left is None and ptr.right is None):
        for i in range(0,n,1):
            print(paths[i]),
        print("\n")
        
    else:
        displayPaths(ptr.left,paths,n)
        displayPaths(ptr.right,paths,n)

def display(ptr,level):
    x=" "
    if ptr is None:
        return
    else: 
        print(ptr.info),
        display(ptr.left,level+1)
        display(ptr.right,level+1)
        

if __name__=='__main__':
    root=None
    path=[0]*100
    while(1):
        print("1.Leaf nodes\n");
        print("2.Insert\n");
        print("3.size\n");
        print("4.Min height\n");
        print("5.Destroy\n");
        print("6.Display Ancestors\n");
        print("7.display Paths\n");
        print("8.Display\n");
        print("9.Quit\n\n");
        print("Enter your choice : ");
        choice=int(input())
        if(choice==1):
            value=leaf_nodes(root)
            print("number of leafs",value)
        elif(choice==2):
            print("Enter key to be inserted")
            value=int(input())
            root=insert(root,value)
        elif(choice==3):
            value=size(root)
            print("size of tree is",value)
        elif(choice==4):
            print("the min height",minht(root))
        elif(choice==5):
            root=Destroy(root)
        elif(choice==6):
            print("Enter an item whose ancestors are to be displayed :")
            item=int(input())
            displayAncestors(root,item)
        elif(choice==7):
            displayPaths(root,path,0)
        elif(choice==8):
            display(root,0)
        elif(choice==9):
            sys.exit(0)
        else:
            sys.exit(0)