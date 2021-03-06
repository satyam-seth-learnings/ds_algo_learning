class Node:
 
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		self.height = 1
 
 
class AVL:
 
	def getHeight(self, root):
		if not root:
			return 0
		return root.height 
 
	def getBalance(self, root):
		if not root:
			return 0
		return self.getHeight(root.left) - self.getHeight(root.right)
 
	def leftRotate(self, p):
		y = p.right 
		temp = y.left 
		y.left = p
		p.right = temp 
		p.height = 1 + max(self.getHeight(p.left), self.getHeight(p.right))
		y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
		return y
 
	def rightRotate(self, p):
		y = p.left 
		t = y.right 
		y.right = p
		p.left = t 
		p.height = 1 + max(self.getHeight(p.left), self.getHeight(p.right))
		y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
		return y
 
	def insertion(self, root, key):
		if not root:
			return Node(key)
		elif key < root.data:
			root.left = self.insertion(root.left, key)
		else:
			root.right = self.insertion(root.right, key)
		root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))
		#find the balance factor and balance tree
		balanceFactor = self.getBalance(root)
		if balanceFactor < -1:
			if key > root.right.data:
				return self.leftRotate(root)
			else:
				root.right = self.rightRotate(root.right)
				return self.leftRotate(root)
		if balanceFactor > 1:
			if key < root.left.data:
				return self.rightRotate(root)
			else:
				root.left = self.leftRotate(root.left)
				return self.rightRotate(root)
		return root 
 
	def getMinValueNode(self, root):
		if root is None or root.left is None:
			return root
		return self.getMinValueNode(root.left)
 
	def deletion(self, root, key):
		if not root:
			return root 
		elif key < root.data:
			root.left = self.deletion(root.left, key)
		elif key > root.data:
			root.right = self.deletion(root.right, key)
		else:
			if root.left is None:
				temp = root.right 
				root = None
				return temp 
			elif root.right is None:
				temp = root.left
				root = None
				return temp 
			temp = self.getMinValueNode(root.right)
			root.data = temp.data
			root.right = self.deletion(root.right, temp.data)
		if root is None:
			return None
		root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))
		balanceFactor = self.getBalance(root)
		if balanceFactor < -1:
			if self.getBalance(root.right) <=0:
				return self.leftRotate(root)
			else:
				root.right = self.rightRotate(root.right)
				return self.leftRotate(root)
		if balanceFactor > 1:
			if self.getBalance(root.left) >=0:
				return self.rightRotate(root)
			else:
				root.left = self.leftRotate(root.left)
				return self.rightRotate(root)
		return root
 
	def inorder(self, root):
		if not root:
			return 
		self.inorder(root.left)
		print(root.data)
		self.inorder(root.right)
 
a = AVL()
root = None
for ele in [21, 26, 30, 9, 4, 14, 28, 18, 15, 10, 2, 3, 7]:
	root = a.insertion(root, ele)
a.inorder(root)
a.deletion(root, 21)
print("***")
a.inorder(root)