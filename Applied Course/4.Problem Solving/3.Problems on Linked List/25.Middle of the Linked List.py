# https://leetcode.com/problems/middle-of-the-linked-list/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Logic-1
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        length=0
        temp=head
        while temp!=None:
            length+=1
            temp=temp.next
        length//=2
        temp=head
        while length:
            length-=1
            temp=temp.next
        return temp
# Logic-2
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        fast=slow=head
        while fast and fast.next:
            fast=fast.next.next
            slow=slow.next
        return slow