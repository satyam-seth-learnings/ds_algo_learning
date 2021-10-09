# https://leetcode.com/problems/remove-nth-node-from-end-of-list
# Logic-1 Counting
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy=ListNode(0)
        dummy.next=head
        #find length of list
        length=0
        first=head
        while first:
            length+=1
            first=first.next
        length-=n
        first=dummy
        while length>0:
            length-=1
            first=first.next
        # update the link
        first.next=first.next.next
        return dummy.next
# Logic-2 Two pointer Approach
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy=ListNode(0)
        dummy.next=head
        first=dummy
        second=dummy
        for i in range(n+1):
            first=first.next
        while first:
            first=first.next
            second=second.next
        second.next=second.next.next
        return dummy.next