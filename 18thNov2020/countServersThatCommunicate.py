class Solution(object):
    # Loop row wise and column wise and find the list of isolated servers
    # Find the set intersection of the row wise isolated servers and column
    # wise isolated servers and subtract it with the total servers.
    def countServers(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        servers=0
        row_isolated=[]
        column_isolated=[]
        # Columns wise looping
        for i in range(len(grid)):
            temp_isolated=[]
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    temp_isolated.append((i,j))
                    servers+=1
            if len(temp_isolated)==1:
                column_isolated.append(temp_isolated[0])
    
        # Row wise loopinh
        for i in range(len(grid[0])):
            temp_isolated=[]
            for j in range(len(grid)):
                if grid[j][i]==1:
                    temp_isolated.append((j,i))
            if len(temp_isolated)==1:
                row_isolated.append(temp_isolated[0])

        # Set Intersection
        isolated=len(set(row_isolated).intersection(set(column_isolated)))
        return servers-isolated

def main():
    # Get input grid from user and execute class method on it
    rows = int(input("Enter the number of rows:")) 
    columns = int(input("Enter the number of columns:")) 
    sol= Solution()
    # Initialize matrix 
    input_grid = [] 
    print("Enter the entries row-wise:") 
      
    # For user input 
    for i in range(rows):           
        a =[] 
        for j in range(columns):
             a.append(int(input())) 
        input_grid.append(a) 
    print(sol.countServers(input_grid))
if __name__=='__main__':
    main()
