class Solution(object):
    # Recursively go right, left and stay and check if max_steps== steps and
    # pos=0 simultaneusly.
    # Add a dict for memoization with steps and pos as key.
    def steps_fn(self, pos, steps, max_steps, arrLen, dict_dp):
        temp_str=str(steps)+'_'+str(pos)
        if temp_str in dict_dp:
            return dict_dp[temp_str]
        if pos==arrLen or pos==-1:
            return 0
        if steps==max_steps and pos==0:
            return 1
        elif steps==max_steps and pos!=0:
            return 0
        else:
            next1=self.steps_fn(pos+1,steps+1, max_steps, arrLen, dict_dp)
            same=self.steps_fn(pos,steps+1, max_steps, arrLen, dict_dp)
            prev=self.steps_fn(pos-1,steps+1, max_steps, arrLen, dict_dp)
            string=str(steps)+'_'+str(pos)
            dict_dp[string]=next1+same+prev
            return (next1+same+prev)%(10**9+7)
    def numWays(self, steps, arrLen):
        """
        :type steps: int
        :type arrLen: int
        :rtype: int
        """
        return self.steps_fn(0,0,steps, arrLen, {})
def main():
    sol=Solution()
    steps, arrLen = int(raw_input()), int(raw_input())
    result=sol.numWays(steps, arrLen)
    print(result)
if __name__=='__main__':
    main()
