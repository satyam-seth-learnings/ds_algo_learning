# Create Node Class
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
# Linked List class contains a Node object 
class LinkedList:
    def __init__(self):
        self.head=None
    # This function prints contents of linked list 
    def print_list(self):
        temp=self.head
        while temp:
            print(temp.data,end=" ")
            temp=temp.next
        print()
# Insertion
    # At the front of linked list
    def push(self,data):
        new_node=Node(data)
        new_node.next=self.head
        self.head=new_node
    # Add a node after a given value
    def after_value(self,data,value):
        new_node=Node(data)
        temp=self.head
        while temp.data!=value:
            temp=temp.next
        new_node.next=temp.next
        temp.next=new_node
    # Add a node after a given node
    def after_node(self,prev_node,data):
        if prev_node is None:
            print("Given node not exist into linked list")
            return
        new_node=Node(data)
        new_node.next=prev_node.next
        prev_node.next=new_node
    # Add a node at the end
    def atend(slef,data):
        new_node=Node(data)
        temp=slef.head
        if temp is None:
            slef.head=new_node
            return
        while temp.next:
            temp=temp.next
        temp.next=new_node
    # Delete the node by value
    def delete_node(self,key):
        # if deleted node is head
        temp=self.head
        if temp and temp.data==key:
            self.head=temp.next
            temp=None
            return
        # if deleted node is not head node
        prev=None
        while temp and temp.data!=key:
            prev=temp
            temp=temp.next
        if temp is None:
            return
        prev.next=temp.next
        temp=None
    # delete the node by position
    def delete_pos(self,pos):
        temp=self.head
        if temp==None:
            return
        if pos==0:
            self.head=temp.next
            temp=None
            return
        prev=None
        count=1
        while temp and count!=pos:
            prev=temp
            temp=temp.next
            count+=1
        if temp is None:
            return
        prev.next=temp.next
        temp=None
    # count number of node
    # iterative method
    def get_count(self):
        temp=self.head
        count=0
        while temp:
            count+=1
            temp=temp.next
        return count
    # recursive method
    def count_rev(self,node):
        if node==None:
            return 0
        return 1+self.count_rev(node.next)
    def count_r(self):
        return self.count_rev(self.head)
if __name__=='__main__':
    list1=LinkedList()
    list1.head=Node(1)
    second=Node(2)
    thired=Node(3)
    list1.head.next=second
    second.next=thired
    list1.print_list()
    list1.push(0)
    list1.print_list()
    list1.after_value(10,2)
    list1.print_list()
    list1.after_node(list1.head.next,20)
    list1.print_list()
    list1.atend(100)
    list1.print_list()
    list1.delete_node(0)
    list1.print_list()
    list1.delete_node(3)
    list1.print_list()
    list1.delete_pos(0)
    list1.print_list()
    list1.delete_pos(4)
    list1.print_list()
    list1.delete_pos(2)
    list1.print_list()
    list1.delete_pos(4)
    list1.print_list()
    print(list1.get_count())
    print(list1.count_r())