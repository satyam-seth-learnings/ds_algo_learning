class Listnode:
    def __init__(self,info):
        self.info=info
        self.prev=None
        self.next=None
class Treenode:
    def __init__(self,info):
        self.info=info
        self.left=None
        self.right=None
        
def createList(temp,n):
    start=None
    for i in range(n):
        info=int(input())
        if start is None:
            start=addtoEmpty(start,info)
        else:
            start=addtoEnd(start,info)
    return start

def addtoEmpty(start,info):
    start=Listnode(info)
    return start

def addtoEnd(start,info):
    temp=Listnode(info)
    p=start
    while p.next:
        p=p.next
    p.next=temp
    temp.prev=p
    return start

def construct(post,ino,n):
    if n==0:
        return None
    ptr=post
    for i in range(1,n):
        ptr=ptr.next
    temp=Treenode(ptr.info)
    if n==1:
        return temp
    q=ino
    i=0
    while q.info!=ptr.info:
        q=q.next
        i+=1
    temp.left=construct(post,ino,i)
    for j in range(1,i+1):
        post=post.next
    temp.right=construct(post,q.next,n-i-1)
    return temp

def inorder(ptr):
    if(ptr==None):
        return
    inorder(ptr.left)
    print(ptr.info)
    inorder(ptr.right)
    
if __name__=='__main__':
    post=None
    ino=None
    n=int(input("enter the number of nodes"))
    print("Enter the postorder list")
    post=createList(post,n)
    print("Enter the inorder list")
    ino=createList(ino,n)
    root=construct(post,ino,n)
    print("inorder traversal of the tree")
    inorder(root)
