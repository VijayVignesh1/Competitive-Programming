# start from max k-repeating word and iteratively find if the k-repeating word is
# a substring of sequence. If so, return count and break.
class Solution(object):
    def maxRepeating(self, sequence, word):
        """
        :type sequence: str
        :type word: str
        :rtype: int
        """
        count=0
        for i in range(len(sequence)/len(word),0,-1):
            if sequence.find(word*i)!=-1:
                count=i
                break
        return count

def main():
    # Get the sequence and word strings as input and apply class methods
    sol=Solution()
    sequence=input("Enter Sequence")
    word=input("Enter Word")
    print(sol.maxRepeating(sequence,word))
    
if __name__=='__main__':
    main()
