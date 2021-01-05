"""
Inspiration came from Professor Thorston Altenkirch and
Computerphile - https://youtu.be/G_UYXzGuqvM
"""
import numpy as np

def possible(grid, y, x, n):
    return(horCheck(grid, y, n) and verCheck(grid, x, n) and sqrCheck(grid, x, y, n))

def horCheck(grid, y, n):
    for i in range(9):
        if grid[y][i] == n:
            return(False)
    return(True)

def verCheck(grid, x, n):
    for i in range(9):
        if grid[i][x] == n:
            return(False)
    return(True)

def sqrCheck(grid, x, y, n):
    x0 = (x//3) * 3
    y0 = (y//3) * 3
    for i in range(3):
        for j in range(3):
            if grid[y0+i][x0+j] == n:
                return(False)
    return(True)

def solve(grid):
    for y in range(9):
        for x in range(9):
            if grid[y][x] == 0:
                for n in range(1, 10):
                    if possible(grid, y, x, n):
                        grid[y][x] = n
                        solve(grid)
                        grid[y][x] = 0
                return

    print(np.matrix(grid))
    input("Next? <Press Enter>")

if __name__ == "__main__":

    grid = [[5,3,0,0,7,0,0,0,0],
            [6,0,0,1,9,5,0,0,0],
            [0,9,8,0,0,0,0,6,0],
            [8,0,0,0,6,0,0,0,3],
            [4,0,0,8,0,3,0,0,1],
            [7,0,0,0,2,0,0,0,6],
            [0,6,0,0,0,0,2,8,0],
            [0,0,0,4,1,9,0,0,5],
            [0,0,0,0,8,0,0,7,9]]
    solve(grid)
