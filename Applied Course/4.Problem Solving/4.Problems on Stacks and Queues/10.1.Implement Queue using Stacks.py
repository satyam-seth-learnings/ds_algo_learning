class MyQueue:

	def __init__(self):
	    """
	    Initialize your data structure here.
	    """
	    self.stack =[]
	    self.stack1 =[]
	    
	
	def push(self, x):
	    """
	    Push element x to the back of queue.
	    """
	    self.stack.append(x)
	    self.stack1 =self.stack[::-1]
	    
	
	def pop(self):
	    """
	    Removes the element from in front of queue and returns that element.
	    """
	    i = self.stack1.pop()
	    self.stack =self.stack1[::-1]
	    return i
	    
	
	def peek(self):
	    """
	    Get the front element.
	    """
	    return self.stack[0]
	    
	
	def empty(self):
	    """
	    Returns whether the queue is empty.
	    """
	    if (len(self.stack)==0):
	        return True
	    return False