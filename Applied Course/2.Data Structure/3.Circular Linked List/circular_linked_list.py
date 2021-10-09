import sys

class Node:
    def __init__(self,info,next=None):
        self.info=info
        self.next=next

class LinkedList:
    def __init__(self):
        self.head=None
    
    def insert_at_beg(self,ele):
        new_node=Node(ele)
        if self.head == None:
            self.head=new_node
            self.head.next=self.head
        else:
            current=self.head
            while current.next != self.head:
                current=current.next
            new_node.next=self.head
            current.next=new_node
            self.head=new_node
    
    def insert_at_end(self,ele):
        new_node=Node(ele)
        if self.head == None:
            self.head=new_node
            self.head.next=self.head
        else:
            current=self.head
            while current.next != self.head:
                current=current.next
            current.next=new_node
            new_node.next=self.head

    def insert_after_given_node(self,ele,item):
        if self.head == None:
            print('List is empty.')
            return
        p=self.head
        while p.next != self.head:
            if p.info == item:
                new_node=Node(ele)
                new_node.next=p.next
                p.next=new_node
                return
            p=p.next
        if p.info == item:
            new_node=Node(ele)
            p.next=new_node
            new_node.next=self.head

    def delete(self,ele):
        if self.head is None:
            print("List is empty.")
            return
        if self.head.next==self.head:
            if self.head.info==ele:
                self.head=None
                return
            else:
                print("element not found")
                return
        if self.head.next.info==ele:
            temp=self.head.next
            self.head.next=temp.next
            return
        p=self.head.next
        while p.next != self.head:
            if p.next.info==ele:
                temp=p.next
                p.next=temp.next
                return
            p=p.next
        if self.head.info==ele:    
            self.temp=self.head
            p.next=self.head.next
            self.head=p.next
            return
    
    def display(self):
        if self.head == None:
            print('List is empty.')
        else:
            current=self.head 
            while current.next is not self.head: 
                print(current.info)
                current=current.next
            print(current.info)

if __name__=='__main__': 

    llist = LinkedList()
    while(1):
        print("1.Display\n")
        print("2.Insert new node at the beginning\n")
        print("3.Insert new node at the end\n")
        print("4.Insert new node after the given node\n")
        print("5.Delete node\n")
        print("6.Quit\n\n")
        print("Enter your choice : ")
        choice=int(input())
        if(choice==1):
            llist.display()
        elif(choice==2):
            value=int(input())
            llist.insert_at_beg(value)
        elif(choice==3):
            value=int(input())
            llist.insert_at_end(value)
        elif(choice==4):
            print("enter the value")
            value=int(input())
            print("Enter the element after which to insert : ")
            item=int(input())
            llist.insert_after_given_node(value,item)
        elif(choice==5):
            value=int(input())
            llist.delete(value) 
        else:
            sys.exit(0)