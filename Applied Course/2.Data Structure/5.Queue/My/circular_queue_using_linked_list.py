class Node:
    def __init__(self,info,next=None):
        self.info=info
        self.next=next

class CircularQueue:
    def __init__(self):
        self.front=self.rear=None
    
    def enqueue(self,ele):
        temp=Node(ele)
        if self.front == None:
            self.front=temp
        else:
            self.rear.next=temp
        self.rear=temp
        self.rear.next=self.front
    
    def dequeue(self):
        if self.front == None:
            print('Queue is empty')
            return -1
        temp=self.front
        if self.front == self.rear:
            self.front=self.rear=None
        else:
            self.front=temp.next
            self.rear.next=self.front
        return temp.info
    
    def display(self):
        if self.front == None:
            print('Queue is empty')
            return
        currnet=self.front
        while currnet.next != self.front:
            print(currnet.info)
            currnet=currnet.next
        print(currnet.info)
c=CircularQueue()
c.enqueue(10)
c.enqueue(20)
c.enqueue(30)
c.display()
print('********')
val=c.dequeue()
if val == -1:
    print('Queue is enpty')
else:
    print(f'Delete element from the queue is {val}')
c.display()