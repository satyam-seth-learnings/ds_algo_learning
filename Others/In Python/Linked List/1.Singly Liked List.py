# Singly Linked List

# for creating a new node
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

# for implementing liked list
class Linked_List:

    def __init__(self):
        self.head=None

    # for print the liked list
    def print_list(self):
        cur_node=self.head
        while cur_node:
            print(cur_node.data)
            cur_node=cur_node.next

    # for insert data into liked list
    def append(self,data):
        new_node=Node(data)
        
        # for insert node into empty list
        if self.head is None:
            self.head=new_node
            return

        # for insert node at end of the liked list
        last_node=self.head
        while last_node.next:
            last_node=last_node.next
        last_node.next=new_node
    
    # for insert node at the begining of the liked list
    def prepend(self,data):
        new_node=Node(data)
        new_node.next=self.head
        self.head=new_node

    # for insert node after a given node into liked list
    def insert_after_node(self,prev_node,data):
        if not prev_node:
            print("Previous None is not in the list")
            return
        new_node=Node(data)
        new_node.next=prev_node.next
        prev_node.next=new_node

    # for delete node of the linked list
    def delete_node(self,key):
        
        # if key is head of the Linked list
        cur_node=self.head
        if cur_node and cur_node.data==key:
            self.head=cur_node.next
            cur_node=None
            return

        # if key is not head of th Linked list
        
        prev=None
        while cur_node and cur_node.data !=key:
            prev=cur_node
            cur_node=cur_node.next
        if cur_node is None:
            return
        prev.next=cur_node.next
        cur_node=None

    # delete node at nth position
    def del_at_pos(self,pos):
        cur_node=self.head

        if pos==1:
            self.head=cur_node.next
            cur_node=None
            return
        
        prev=None
        count=1
        while cur_node and count!=pos:
            prev=cur_node
            cur_node=cur_node.next
            count+=1

        if cur_node is None:
            return
        
        prev.next=cur_node.next
        cur_node=None

    # find the length of of linked list
    # iterative method
    def len_iterative(self):
        count=0
        cur_node=self.head
        while cur_node:
            count+=1
            cur_node=cur_node.next
        return f"length of linked list is {count}"

    # recusive method
    def len_recursive(self,node):
        if node is None:
            return 0
        return 1+self.len_recursive(node.next)

l=Linked_List()
l.append("6")
l.append("8")
l.print_list()
print("------")
l.prepend("1")
l.print_list()
print("------")
l.insert_after_node(l.head.next,"2")
l.print_list()
print("------")
l.delete_node("2")
l.print_list()
print("------")
l.delete_node("1")
l.print_list()
print("------")
l.append("A")
l.append("B")
l.print_list()
print("------")
l.del_at_pos(2)
l.print_list()
print("------")
l.del_at_pos(1)
l.print_list()
l.del_at_pos(10)
print(l.len_iterative())
print(f"Length Of Linked List Is {l.len_recursive(l.head)}")