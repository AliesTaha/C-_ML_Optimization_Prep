# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev=head
        curr=head     
        next=head.next

        if (not head or not head.next):
            return head

        while (next):
            curr=next
            next=curr.next
            curr.next=prev
            prev=curr
        
        return curr