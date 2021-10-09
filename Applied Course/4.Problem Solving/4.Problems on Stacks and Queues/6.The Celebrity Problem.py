import sys
mat=[[0,0,0,0,1],
     [0,0,0,0,1],
     [0,0,0,0,1],
     [0,0,0,0,1],
     [0,0,0,0,0]]
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
            
    def getSize(self):
        self.p=self.top
        count=0
        while self.p is not None:
            count+=1
            self.p=self.p.next
            
def haveAquantiance(a,b):
    return mat[a][b]

def findCeleb(n):
    stack=Stack()
    for i in range(n):
        stack.push(i)
        
    temp1=stack.pop()
    temp2=stack.pop()
    
    while(stack.getSize()>1):
        if(haveAquantiance(temp1,temp2)):
            temp1=stack.pop()
        else:
            temp2=stack.pop()
    celeb=stack.pop()
    if(haveAquantiance(celeb,temp2)):
        celeb=temp2
    if(haveAquantiance(celeb,temp1)):
        celeb=temp1
    
    for i in range(n):
        if(i!=celeb and haveAquantiance(celeb,i) and haveAquantiance(i,celeb)!=1):
            return -1
    return celeb
    
if __name__=='__main__':
    val=findCeleb(5)
    if(val>0):
        print("Celebrity found {}".format(val))
    else:
        print("Celebrity not found")
