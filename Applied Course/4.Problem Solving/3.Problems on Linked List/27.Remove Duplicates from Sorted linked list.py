# https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy=ListNode(0)
        dummy.next=head
        prev,current=dummy,head
        while current!=None:
            while current.next!=None and prev.next.val==current.next.val:
                current=current.next
            if prev.next==current:
                prev=current
            else:
                prev.next=current.next
            current=current.next
        return dummy.next