# Hello World program in Python
    
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        temp=root
        if root==None:
            root=TreeNode(val)
            return root
        while True:
            if temp.val>val and temp.left==None:
                temp.left=TreeNode(val)
                break
            if temp.val>val and temp.left!=None:
                temp=temp.left
                continue
            if temp.val<val and temp.right==None:
                temp.right=TreeNode(val)
                break
            if temp.val<val and temp.right!=None:
                temp=temp.right
                continue
        return root

def array_to_bst(array_nums):
    if not array_nums:
        return None
    mid_num = len(array_nums)//2
    node = TreeNode(array_nums[mid_num])
    node.left = array_to_bst(array_nums[:mid_num])
    node.right = array_to_bst(array_nums[mid_num+1:])
    return node

def printPreOrder(node): 
    if not node: 
        return      
    print(node.val)
    printPreOrder(node.left) 
    printPreOrder(node.right)   

def main():
    sol=Solution()
    array=list(map(str,raw_input("Enter values of Binary Search Tree").split()))
    num=int(input("Enter Number to be inserted"))
    # print(printPreOrder(array_to_bst(array)))
    array=array_to_bst(array)
    result=sol.insertIntoBST(array,num)
    printPreOrder(result)
if __name__=='__main__':
    main()
