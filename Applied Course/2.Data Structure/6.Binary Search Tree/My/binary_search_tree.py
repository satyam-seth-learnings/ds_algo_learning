class Node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

class BST:
    def insertion(self,root,ele):
        if root == None:
            return Node(ele)
        if ele < root.data:
            root.left=self.insertion(root.left,ele)
        else:
            root.right=self.insertion(root.right,ele)
        return root

    def search(self,root,ele):
        if root == None or root.data == ele:
            return root
        elif root.data > ele:
            return self.search(root.left,ele)
        else:
            return self.search(root.right,ele)

    def min_value(self,root):
        if root == None or root.left == None:
            return root
        else:
            return self.min_value(root.left)

    def max_value(self,root):
        if root == None or root.right == None:
            return root
        else:
            return self.max_value(root.right)

    def preorder(self,root):
        if root == None:
            return
        print(root.data)
        self.preorder(root.left)
        self.preorder(root.right)

    def inorder(self,root):
        if root == None:
            return
        self.inorder(root.left)
        print(root.data)
        self.inorder(root.right)

    def postorder(self,root):
        if root == None:
            return
        self.postorder(root.left)
        self.postorder(root.right)
        print(root.data)

    def iterative_preorder(self,root):
        if root is None:
            return
        stack=[]
        stack.append(root)
        while stack:
            current=stack.pop()
            print(current.data)
            if current.right:
                stack.append(current.right)
            if current.left:
                stack.append(current.left)

    def iterative_inorder(self,root):
        current=root
        stack=[]
        while True:
            if  current:
                stack.append(current)
                current=current.left
            elif stack:
                current=stack.pop()
                print(current.data)
                current=current.right
            else:
                break
        
    def iterative_postorder(self,root):
        if root is None:
            return 
        recursiveStack,resultStack=[],[]
        recursiveStack.append(root)
        while recursiveStack:
            current = recursiveStack.pop()
            resultStack.append(current)
            if current.left:
                recursiveStack.append(current.left)
            if current.right:
                recursiveStack.append(current.right)
        while resultStack:
            current = resultStack.pop()
            print(current.data)

    def iterative_postorder2(self,root):
        if root is None:
            return 
        stack = []
        prev = None
        stack.append(root)
        while stack:
            current = stack[-1]
            if prev == None or prev.left == current or prev.right == current:
                if current.left:
                    stack.append(current.left)
                elif current.right:
                    stack.append(current.right)
                else:
                    print(current.data)
                    stack.pop()
            elif prev == current.left:
                if current.right:
                    stack.append(current.right)
            else:
                print(current.data)
                stack.pop()
            prev = current

    def successor(self, root):
        root = root.right
        while root.left:
            root = root.left
        return root.data

    def predecessor(self, root):
        root = root.left
        while root.right:
            root = root.right
        return root.data

    def deletion(self, root, key):
        if not root:
            return None

        if key < root.data:
            root.left = self.deletion(root.left, key)
        elif key > root.data:
            root.right = self.deletion(root.right, key)
        else:
            if not (root.left or root.right):
                root = None

            elif root.right:
                root.data = self.successor(root)
                root.right = self.deletion(root.right, root.data)

            else:
                root.data = self.predecessor(root)
                root.left = self.deletion(root.left, root.data)
        return root

root=None
b=BST()
for ele in [10,5,25,2,7,30]:
    root=b.insertion(root,ele)
print('Preorder:')
b.preorder(root)
print('Inorder:')
b.inorder(root)
print('Postorder:')
b.postorder(root)
b.deletion(root,7)
print('Iterative Preorder:')
b.iterative_preorder(root)
print('Iterative Inorder:')
b.iterative_inorder(root)
print('Iterative Postorder:')
b.iterative_postorder(root)
print('Iterative Postorder 2:')
b.iterative_postorder2(root)
search_ele=b.search(root,7)
if search_ele:
    print('Element {} is found in the BST'.format(search_ele.data))
else:
    print('Element is not found')
min_ele=b.min_value(root)
if min_ele:
    print('Minimum Element is {}'.format(min_ele.data))
else:
    print('Tree Empty')
max_ele=b.max_value(root)
if max_ele:
    print('Maximum Element is {}'.format(max_ele.data))
else:
    print('Tree Empty')