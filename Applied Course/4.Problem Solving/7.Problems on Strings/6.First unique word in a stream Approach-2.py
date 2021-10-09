class Node :
	def __init__(self, data = None, prev = None, nxt = None) :
		self.data = data
		self.prev = prev
		self.next = nxt

class DLL :
	def __init__(self) :
		self.front = self.rear = None
		
	def insert(self, key) :
		newNode = Node(key)
		if self.front is None :
			self.front = self.rear = newNode
		else :
			self.rear.next = newNode
			newNode.prev = self.rear
			self.rear = newNode
		return newNode
		
	def delete(self, ptr) :
		if self.rear == self.front == ptr :
		    self.rear = self.front = None
		else :
		    if ptr == self.front :
		        self.front = self.front.next
		        ptr = None
		    elif ptr == self.rear :
		        self.rear = self.rear.prev
		        ptr = None
		    else :
		        ptr.prev.nxt = ptr.next
		        ptr.next.prev = ptr.prev
		        ptr = None

	def get_front(self) :
		return self.front.data

def fun2() :
	freq = dict()
	dll = DLL()
	while 1 :
	    x = input('Enter a character:')
	    if x == 'exit' :
	        return
	    if x not in freq.keys() :
	        freq[x] = [1,dll.insert(x)]
	    else :
	        dll.delete(freq[x][1])
	        freq.pop(x)
	    print("First non-repeating character: {}".format(dll.get_front()))
	    
fun2()

