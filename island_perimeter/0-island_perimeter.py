#!/usr/bin/python3
"""
island permieter module
"""


def island_perimeter(grid):
    """ Returns the perimeter of the island described in grid
    """
    perimter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # add 4 sides to perimeter
                perimter += 4

                # if neighboring land remove 2 to perimeter
                # Top land
                if i > 0 and grid[i - 1][j] == 1:
                    perimter -= 2
                # Left land
                if j > 0 and grid[i][j - 1] == 1:
                    perimter -= 2

    return perimter
