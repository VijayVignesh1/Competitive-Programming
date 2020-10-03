class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        count_dict=[]
        result=0
        nums.sort()
        for i in range(len(nums)):
            for j in range(i,len(nums)):
                if(i==j):
                    continue
                if(abs(nums[j]-nums[i])==k):
                    # print(i,j)
                    key=str(max(nums[i],nums[j]))+"-"+str(min(nums[i],nums[j]))
                    if key not in count_dict:
                        count_dict.append(key)
                        result+=1
                    else:
                        pass
                if(nums[j]-nums[i]>k):
                    break
        # print(count_dict)
        return result
        
def main():
    sol=Solution()
    list_str=raw_input("Enter the array: \n").split()
    arr=list(map(int,list_str))
    diff_k=int(input("Enter the difference value: \n"))
    result=sol.findPairs(arr,diff_k)
    print("Number of Unique pairs is: %d"%(result))

if __name__=="__main__":
    main()
