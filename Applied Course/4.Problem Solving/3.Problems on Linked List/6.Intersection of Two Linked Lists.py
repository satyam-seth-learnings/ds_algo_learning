# https://leetcode.com/problems/intersection-of-two-linked-lists/
import sys
class node: 

    def __init__(self, info): 
        self.info = info  
        self.next = None 


class LinkedList: 

    def __init__(self): 
        self.head = None


    def display(self):
        temp = self.head 
        while (temp): 
            print(temp.info)
            temp = temp.next
    
    def count(self):
        count=0
        temp=self.head
        while(temp):
            count+=1
            temp=temp.next
        return count
    
    def serach(self,value):
        temp=self.head
        pos=1
        while(temp):
            if(temp.info==value):
                print("The value found at",pos)
            temp=temp.next
            pos+=1
        print("Value not found in the linked list")
    def insert_at_beg(self,data):
        self.temp = node(data)
        if self.head is None:
            self.head = self.temp
            return
        self.temp.next = self.head
        self.head= self.temp
    def insert_at_end(self,data):
        self.temp = node(data)
        if self.head is None:
            self.head = self.temp
            return
        self.p = self.head
        while self.p.next is not None:
            self.p=self.p.next
        self.p.next = self.temp;
        
    def insert_after_given_node(self,data,item):
        self.p=self.head
        while self.p is not None:
            if(self.p.info==item):
                self.temp=node(data)
                self.temp.next=self.p.next
                self.p.next=self.temp
                return
            self.p=self.p.next
        print("Item not found")

    def insert_at_pos(self,data,pos):
        self.temp=node(data)
        if pos==1:
            self.temp.next = self.head
            self.head= self.temp
            return
        self.p=self.head
        while pos>2 and self.p is not None:
            self.p=self.p.next
            pos-=1
        if self.p is None:
            print("Position exceeded the length of the list")
        else:
            self.temp.next=self.p.next
            self.p.next=self.temp
    def delete(self,data):
        if self.head is None:
            print("List is empty")
            return
        if self.head.info==data:
            self.temp=self.head
            self.head=self.head.next
            return
        self.p=None
        self.curr=self.head
        while self.curr is not None:
            if self.curr.info==data:
                self.temp=self.p.next
                self.p.next=self.temp.next
                return
            self.p=self.curr
            self.curr=self.curr.next
def count(head):
    count=0
    temp=head
    while(temp):
        count+=1
        temp=temp.next
    return count
def intersection(head1,head2):
    t1=count(head1)
    t2=count(head2)
    if t1>t2:
        d=t1-t2
        return getIntersection(head1,head2,d)
    else:
        d=t2-t1
        return getIntersection(head2,head1,d)
def getIntersection(head1,head2,d):
    temp1=head1
    temp2=head2
    for i in range(d):
        temp1=temp1.next
    while temp1 is not None and temp2 is not None:
        if temp1==temp2:
            return temp1.info
        temp1=temp1.next
        temp2=temp2.next
    
    return -1
if __name__=='__main__':
    llist1=LinkedList()
    llist2=LinkedList()
    print("enter the length of list1")
    n=int(input())
    for i in range(n):
        llist1.insert_at_end(int(input()))
    print("enter the length of list2")
    m=int(input())
    for i in range(m):
        llist2.insert_at_end(int(input()))
    temp1=llist1.head
    temp2=llist2.head
    while temp2.next is not None:
        temp2=temp2.next
    temp2.next=temp1.next.next.next
    temp2=llist2.head
    print("Merged List1")
    while temp1 is not None:
        print(temp1.info)
        temp1=temp1.next
    print("Merged List2")
    while temp2 is not None:
        print(temp2.info)
        temp2=temp2.next
    print("intersection node",intersection(llist1.head,llist2.head))
