class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        if not grid:
            return 0
        mem = [[0 for i in range(n)] for i in range(m)]
        mem[0][0] = grid[0][0]
        for i in range(1,m):
            mem[i][0] = mem[i-1][0] + grid[i][0]
            
        for i in range(1,n):
            mem[0][i] = mem[0][i-1] + grid[0][i]
            
        for i in range(1,m):
            for j in range(1,n):
                mem[i][j] = min(mem[i-1][j],mem[i][j-1]) + grid[i][j]
        return mem[-1][-1]