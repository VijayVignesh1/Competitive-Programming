class Solution(object):
    # Find the indices of all zeros and make sure the non-zero valued indices
    # before that particular zero has a value that can hop to indices after the
    # zero.
    # E.g. [3,2,1,0,4] --> Values before zero does not have value to cross the zero
    # #.g. [4,2,1,0,4] --> Value at index 1 (4) can cross 0, hence return true.
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums)==1:
            return 1
        zero=[i for i in range(len(nums)) if nums[i]==0]
        for i in range(len(zero)):
            start=zero[i]-1
            end=-1
            flag=0
            for j in range(start, end, -1):
                if nums[j]==0:
                    continue
                if zero[i]!=len(nums)-1:
                    if j+nums[j]>zero[i]:
                        flag=1
                        break
                else:
                    if j+nums[j]>=zero[i]:
                        flag=1
                        break                    
            if flag==0:
                return 0
        return 1
        
if __name__=='__main__':
    # Get input from the user and apply the class function to it
    sol=Solution()
    nums=map(int,raw_input().split(" "))
    result=sol.canJump(nums)
    print(result)
