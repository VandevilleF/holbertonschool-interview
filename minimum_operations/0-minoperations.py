#!/usr/bin/python3
"""Find the minimum operations to reach for n"""


def minOperations(n):
    """Find the minimum operations to reach for n"""
    operation = 0
    divisor = 2

    if n <= 1:
        return 0

    while (n > 1):
        while n % divisor == 0:
            operation += divisor
            n //= divisor
        divisor += 1

    return operation
