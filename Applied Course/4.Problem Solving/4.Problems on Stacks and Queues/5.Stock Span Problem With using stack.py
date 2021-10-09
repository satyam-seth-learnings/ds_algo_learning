import sys
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
def calculateSpan(price,n,stock):
    s=Stack()
    s.push(0)
    stock[0]=1
    
    for i in range(1,n):
        
        while s.isEmpty() is not True and price[s.peek()]<=price[i]:
            ele=s.pop()
        
        if s.isEmpty():
            stock[i]=i+1
        else:
            stock[i]=i-s.peek()
        
        s.push(i)
    return stock


if __name__=='__main__':
    price=[10, 4, 5, 90, 120, 80]
    n=len(price)
    stock=[0]*n
    stock=calculateSpan(price,n,stock)
    for i in stock:
        print("{} ".format(i)),
