class Node:
    def __init__(self,info,link=None):
        self.info=info
        self.link=link

class LinkedList:
    def __init__(self):
        self.head=None
    
    def insert_at_beginning(self,info):
        new_node=Node(info)
        if self.head != None:
            new_node.link=self.head
            self.head=new_node
        else:
            self.head=new_node

    def insert_at_end(self,info):
        new_node=Node(info)
        if self.head != None:
            current=self.head
            while current.link != None:
                current=current.link
            current.link=new_node
        else:
            self.head=new_node

    def delete_node(self,ele):
        if self.head == None:
            print('List is empty.')
            return
        if self.head.info == ele:
            temp=self.head
            self.head=temp.link
            temp=None
            return
        current=self.head
        while current.link != None:
            if current.link.info == ele:
                temp=current.link
                current.link=temp.link
                temp=None
                return
            current=current.link
        print('Element is not found in our list.')
        
    def display(self):
        if self.head == None:
            print('List Empty.')
            return
        current=self.head
        while current != None:
            print(current.info)
            current=current.link

    def search(self,ele):
        if self.head == None:
            print('List Empty.')
            return
        currnet=self.head
        while currnet != None:
            if currnet.info == ele:
                print('Element is found in our list.')
                return
            currnet=currnet.link
        print('Element is not found in our list.')

LL=LinkedList()
LL.insert_at_beginning(10)
LL.insert_at_end(5)
LL.display()
print("*******")
LL.insert_at_beginning(15)
LL.insert_at_end(8)
LL.display()
print("*******")
LL.delete_node(15)
LL.display()
LL.search(10)
print("*******")
LL.search(1)