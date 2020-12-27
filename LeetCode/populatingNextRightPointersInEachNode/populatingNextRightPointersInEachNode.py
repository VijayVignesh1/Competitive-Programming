

# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

# Traverse Level by Level
# At each level keep a note of previous node and point previous node's next pointer
# to current node and make currrent node as previous node..till the end of level.
class Solution(object):
    global count
    def height(self,node):
        if node is None:
            return 0
        else :
            # Compute the height of each subtree 
            lheight = self.height(node.left)
            rheight = self.height(node.right)

            #Use the larger one
            if lheight > rheight :
                return lheight+1
            else:
                return rheight+1
    
    def populateGivenLevel(self, root , level, prev_node):
        global count
        if root is None:
            return
        if level == 1:
            if count==0:
                count+=1
                prev_node[0]=root
            else:
                count+=1
                prev_node[0].next=root
                prev_node[0]=root
        elif level > 1 :
            self.populateGivenLevel(root.left , level-1, prev_node)
            self.populateGivenLevel(root.right , level-1, prev_node)

    def populateLevelOrder(self, root):
        global count
        h = self.height(root)
        for i in range(1, h+1):
            count=0
            self.populateGivenLevel(root, i, [root])

    def printGivenLevel(self, root):
        if root is None:
            return
        else:
            print(root.val),
            self.printGivenLevel(root.next)

    
    def printLevelOrder(self,root):
        while root!=None:
            self.printGivenLevel(root)
            root=root.left
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        self.populateLevelOrder(root)
        return root



def array_to_bst(array_nums):
    if not array_nums:
        return None
    mid_num = len(array_nums)//2
    node = Node(array_nums[mid_num])
    node.left = array_to_bst(array_nums[:mid_num])
    node.right = array_to_bst(array_nums[mid_num+1:])
    node.next=None
    return node


def main():
    # Get the array from user, convert it into BST and apply the class method to it
    sol=Solution()
    array=list(map(str,raw_input("Enter values of Binary Search Tree").split()))
    array=array_to_bst(array) # Since the array_to_bst converts the given array keeping
                              # middle node as root, the solutions seems to differ from
                              # that of LeetCode
    result=sol.connect(array)
    sol.printLevelOrder(result)
if __name__=='__main__':
    main()
    
