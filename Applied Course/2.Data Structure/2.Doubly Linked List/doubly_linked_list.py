import sys

class Node:
    def __init__(self,info,prev=None,next=None):
        self.info=info
        self.prev=prev
        self.next=next

class LinkedList:
    def __init__(self):
        self.head=None

    def insert_at_beg(self,ele):
	    new_node=Node(ele)
	    if self.head == None:
	    	self.head=new_node
	    else:
	    	new_node.next=self.head
	    	self.head.prev=new_node
	    	self.head=new_node
    
    def insert_at_end(self,ele):
        new_node=Node(ele)
        if self.head == None:
            self.head=new_node
        else:
            current=self.head
            while current.next != None:
                current=current.next
            current.next=new_node
            new_node.prev=current

    def insert_after_given_node(self,data,item):
        current=self.head
        while current is not None:
            if current.info==item:
                new_node=Node(data)
                new_node.prev=current
                new_node.next=current.next
                if current.next:
                    current.next.prev=new_node
                current.next=new_node
                return
            current=current.next

    def delete(self,ele):
        # base case
        if self.head == None:
            print('List is empty.')
            return
        # if only one node is present
        if self.head.next == None:
            if self.head.info == ele:
                temp=self.head
                self.head=None
                temp=None
                return
            else:
                print('Element is not found in our list.')
                return
        # delete node between
        temp=self.head.next
        while temp.next != None:
            if temp.info == ele:
                temp.prev.next=temp.next
                temp.next.prev=temp.prev
                temp=None
                return 
            temp=temp.next
		#delete last node
        if temp.info == ele:
            temp.prev.next=None
            temp=None
            return
            print("Element is not found in the list")

    def reverse(self):
        if self.head == None:
            return
        p1=self.head
        p2=p1.next
        p1.next=None
        p1.prev=p2
        while p2 is not None:
            p2.prev=p2.next
            p2.next=p1
            p1=p2
            p2=p2.prev
        self.head=p1
        print("List reversed\n")

    def display(self):
        if self.head == None:
            print('List is empty.')
            return
        current=self.head
        while current != None:
            print(current.info)
            current=current.next

if __name__=='__main__': 

    llist = LinkedList() 
    while(1):
        print("1.Display")
        print("2.Insert new node at the beginning")
        print("3.Insert new node at the end")
        print("4.Insert new node after the given node")
        print("5.Delete node")
        print("6.Reverse list")
        print("7.Quit\n")
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
            print("enter the value : ")
            value=int(input())
            print("Enter the element after which to insert : ")
            item=int(input())
            llist.insert_after_given_node(value,item)
        elif(choice==5):
            value=int(input())
            llist.delete(value) 
        elif(choice==6):
            llist.reverse() 
        else:
            sys.exit(0)