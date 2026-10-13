class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        fror = 0
        for row in grid:
            for cell in row:
                if cell == 1:
                    fror += 1

        change = True
        m = 0
        while change:
            change = False
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    if grid[i][j] == 1:
                        if (i + 1 < len(grid) and grid[i + 1][j] == 2 or 
                        i - 1 >= 0 and grid[i - 1][j] == 2 or 
                        j + 1 < len(grid[0]) and grid[i][j + 1] == 2 or 
                        j - 1 >= 0 and grid[i][j - 1] == 2):
                            grid[i][j] = 3
                            fror -= 1
                            change = True

            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    if grid[i][j] == 3:
                        grid[i][j] = 2
                        
            m += 1

        if fror == 0:
            return m - 1

        return -1
