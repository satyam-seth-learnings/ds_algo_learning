class Stack:
    def __init__(self):
        self.stack=[]
    
    def is_empty(self):
        return self.stack==[]

    def push(self,ele):
        self.stack.append(ele)
    
    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        else:
            return -1
    
    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        else:
            return -1
st=Stack()
print(st.is_empty())
st.push(10)
print(st.peek())
print(st.pop())
print(st.is_empty())