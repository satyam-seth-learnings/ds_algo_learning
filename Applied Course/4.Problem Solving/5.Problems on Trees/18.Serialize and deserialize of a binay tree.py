
class Codec:  
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root :
            print("LLLLLLL")
            return root
        def serial(root,arr):
            
            if root is None:
                arr.append("/")
                return 
            arr.append(str(root.val))
            serial(root.left, arr)
            serial(root.right, arr)
            return arr
        arr = []
        arr = serial(root, arr)
        fstring = ','.join(arr)  
        # print(fstring)       
        return fstring
        
 
    def deserialize(self, data):        
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def deserial(string): 
            
            if string[0] == None:              
                return None
            val = string.pop(0)           
            if val == '/' :
                return None    
            root = TreeNode(val)
            root.left = deserial(string)
            root.right = deserial(string)
            return root
    
        index = 0
        if data == None:
            return None
        root = deserial(data.split(','))
        return root
