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
def insert(s,c):
    if s.isEmpty() is True:
        s.push(c)
    else:
        d=s.pop()
        insert(s,c)
        s.push(d)
    return s
def reverse(s):
    if s.isEmpty() is not True:
        c=s.pop()
        reverse(s)
        insert(s,c)
        return s
if __name__=='__main__':
    stack=Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    stack.push(10)
    print("Before reversing")
    stack.display()
    stack=reverse(stack)
    print("After reversing")
    stack.display()
    
