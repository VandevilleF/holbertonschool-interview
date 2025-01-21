#!/usr/bin/python3
"""Find the minimum operations to reach for n"""


def minOperations(n):
    """Find the minimum operations to reach for n"""
    operation = 0
    actuel = 1

    while (actuel < n):
        if (n / actuel):
            operation += 1
            memoire = actuel
        actuel += memoire
        operation += 1

    return operation
