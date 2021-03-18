class Solution(object):
    # Start from first index (precalculate 0th index value)
    # Every index's output is 2*(Prev_sum)+(2^0 * A[index])
    def prefixesDivBy5(self, A):
        """
        :type A: List[int]
        :rtype: List[bool]
        """
        output=[]
        temp_sum=A[0]*(2**0)
        output.append(temp_sum%5==0)
        for i in range(1,len(A)):
            temp_sum=(2*temp_sum)+((2**0)*A[i])
            output.append(temp_sum%5==0)
        return output

def main():
    # Get the input from the user and apply class function to it
    sol=Solution()
    A=list(map(int,raw_input().split(" ")))
    result=sol.prefixesDivBy5(A)
    print(result)
if __name__=='__main__':
    main()
