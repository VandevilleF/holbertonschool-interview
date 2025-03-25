#!/usr/bin/python3
""" Nqueens module
"""
import sys


def nqueens():
    """ Solves the N queens problem.
    """
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print('N must be a number')
        exit(1)

    if n < 4:
        print('N must be at least 4')
        exit(1)

    col = set()
    posDiag = set()  # (r + c)
    negDiag = set()  # (r - c)

    res = []
    board = []  # store the result [[row, col], [row, col]...]

    def backtrack(r):
        """ Backtracking recursive
        """
        if r == n:
            res.append(board[:])  # create a new list with the content of board
            return

        for c in range(n):
            if c in col or (r + c) in posDiag or (r - c) in negDiag:
                continue

            col.add(c)
            posDiag.add(r + c)
            negDiag.add(r - c)
            board.append([r, c])  # store the pos with the format [row, col]

            backtrack(r + 1)

            col.remove(c)
            posDiag.remove(r + c)
            negDiag.remove(r - c)
            board.pop()  # Remove the last adding pos

    backtrack(0)

    # Print results
    for sol in res:
        print(sol)


if __name__ == '__main__':
    nqueens()
