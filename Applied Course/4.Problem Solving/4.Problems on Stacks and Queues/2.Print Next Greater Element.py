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
def nextGreaterEle(arr,n):
    s=Stack()
    s.push(arr[0])
    for i in range(1,n):
        temp=arr[i]
        if s.isEmpty() is not True:
            element=s.pop()
            while(element<temp):
                print("{} -> {}".format(element,temp))
                if s.isEmpty() is True:
                    break
                element=s.pop()
            if element>temp:
                s.push(element)
        s.push(temp)

    while s.isEmpty() is not True:
        element=s.pop()
        temp=-1
        print("{} -> {}".format(element,temp))
    
if __name__=='__main__':
    arr=[4, 3, 2, 1]
    n=len(arr)
    nextGreaterEle(arr,n)
