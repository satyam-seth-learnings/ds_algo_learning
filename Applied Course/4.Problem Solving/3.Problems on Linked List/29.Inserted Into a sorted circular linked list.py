class solution(object):
    def insert(self,head,insertVal):
        if head==None:
            newNode=Node(insertVal,None)
            newNode.next=newNode
            return newNode
        prev,current=head,head.next
        toInsert=False
        while True:
            # logic
            # case1
            if prev.val<=insertVal<=current.val:
                # create a newNode
                toInsert=True
            # case2
            elif prev.val>current.val:
                if prev.val<insertVal or current.val>insertVal:
                    toInsert=True
            if toInsert==True:
                prev.next=Node(insertVal,current)
                return head
            prev,current=current,current.next
            if prev==head:
                break
        # case3 (tricky)
        prev.next=Node(insertVal,current)
        return head