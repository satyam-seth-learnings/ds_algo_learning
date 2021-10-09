# https://leetcode.com/problems/lru-cache/
class DLLNode:
    def __init__(self):
        self.key=0
        self.value=0
        self.prev=None
        self.next=None
        
class LRUCache:
    
    def _remove_node(self,node):
        prev=node.prev 
        next=node.next 
        prev.next=next 
        next.prev=prev 
    
    def _add_node(self,node):
        node.prev=self.head
        node.next=self.head.next
        self.head.next.prev=node
        self.head.next=node
        
    def _remove_tail_node(self):
        res=self.tail.prev
        self._remove_node(res)
        return res
        
    def _move_to_head(self,node):
        self._remove_node(node)
        self._add_node(node)

    def __init__(self, capacity: int):
        self.cache={}
        self.size=0
        self.capacity=capacity
        self.head,self.tail=DLLNode(),DLLNode()
        self.head.next=self.tail
        self.tail.prev=self.head

    def get(self, key: int) -> int:
        node=self.cache.get(key,None)        
        if not node:
            return -1
        # move the item to head
        self._move_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        node=self.cache.get(key)
        if not node:
            newNode=DLLNode()
            newNode.key=key
            newNode.value=value
            self.cache[key]=newNode
            self._add_node(newNode)
            self.size+=1
            if self.size>self.capacity:
                # remove tail node of the cache (dll)
                tail=self._remove_tail_node()
                del self.cache[tail.key]
                self.size-=1
        else:
            node.value=value
            self._move_to_head(node)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)