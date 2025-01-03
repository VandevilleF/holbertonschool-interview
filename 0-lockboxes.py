#!/usr/bin/python3
"""A method that determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """A method that determines if all the boxes can be opened"""
    boxe_open = set([0])
    stack = [0]

    while stack:
        actual_boxe = stack.pop()

        for key in boxes[actual_boxe]:
            if key < len(boxes) and key not in boxe_open:
                # Add the key to the set if it does not already exist
                boxe_open.add(key)
                stack.append(key)

    return len(boxe_open) == len(boxes)
