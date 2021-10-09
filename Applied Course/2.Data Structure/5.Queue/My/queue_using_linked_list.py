class Node:
    def __init__(self,info,next=None):
        self.info=info
        self.next=next

class Queue:
    def __init__(self):
        self.front=None
        self.rear=None

    def is_empty(self):
        return self.front == None
    
    def enqueue(self,ele):
        temp=Node(ele)
        if self.rear == None:
            self.rear=self.front=temp
            return
        self.rear.next=temp
        self.rear=temp

    def dequeue(self):
        if self.is_empty():
            print('Queue Empty')
            return
        temp=self.front
        self.front=temp.next
        if self.front == None:
            self.rear=None

    def display(self):
        if self.is_empty():
            print('Queue Empty')
            return
        p=self.front
        while p != None:
            print(p.info)
            p=p.next
q=Queue()
q.display()
q.enqueue(10)
q.enqueue(20)
q.display()
print('*******')
q.dequeue()
q.display()
q.dequeue()
q.display()
print('*******')
q.dequeue()