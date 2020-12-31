# Find the minimum distance left and right of the index and the minimum of the two
# is the value for the given index
class Solution(object):
    def minDistance(self, string, char, count, add_sub=1):
        if (count==-1 or count==len(string)):
            return 2**15
        elif string[count]==char:
            return count
        else:
            return self.minDistance(string, char, count+add_sub, add_sub)
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        list=[]
        for i in range(0,len(S)):
            list.append(min(abs(i-self.minDistance(S,C,i)),abs(i-self.minDistance(S,C,i,-1))))
        return list
        
def main():
    # Get the String and Character from the user and apply the class function
    sol=Solution()
    S=input("Enter String")
    C=input("Enter Character")
    print(sol.shortestToChar(S,C))
if __name__=='__main__':
    main()
