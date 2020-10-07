# Hello World program in Python
    
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    # Rotates the given linked list given number of times
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head==None:
            return head
        temp=head
        num_count=0
        # Go to the last node and connect it first node to make it
        # a circular linked list
        while temp.next!=None:
            temp=temp.next
            num_count+=1
        num_count+=1
        temp.next=head # Connecting last node and first node
        
        # Make the (count-k-1)th node as the head and connect the node before
        # it to None
        temp=head
        k=k%(num_count)
        i=0
        while(i!=num_count-k-1):
            temp=temp.next
            i+=1
        head=temp.next
        temp.next=None
        return head
    
def list_to_linked_list(num_list):
    prev=None
    for i in num_list[::-1]:
        temp=ListNode(i)
        temp.next=prev
        prev=temp
    return temp
def print_linked_list(head):
    while(head!=None):
        print(head.val,end=' ')
        head=head.next
def main():
    sol=Solution()
    num_list=list(map(str,raw_input("Enter the numbers").split()))
    print(num_list)
    k=int(input("Enter the number of rotations"))
    head=list_to_linked_list(num_list)
    print("List before rotation: ",end=' ')
    print_linked_list(head)
    result_head=sol.rotateRight(head,k)
    print("\n")
    print("List after rotation: ",end=' ')
    print_linked_list(result_head)
    
if __name__=='__main__':
    main()
