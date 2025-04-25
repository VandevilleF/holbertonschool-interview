#!/usr/bin/python3

def rain(walls):
    """Given a list of non-negative integers
    representing the heights of walls with unit width 1"""
    # Si la liste est vide ou trop courte, retourner 0
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)

    # Listes pour les murs max à gauche et à droite de chaque case
    left_max = [0] * n
    right_max = [0] * n

    water = 0  # Total d'eau retenue

    # Initialiser le max gauche pour la première case
    left_max[0] = walls[0]

    # Remplir left_max : max des murs de 0 à i
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Initialiser le max droit pour la dernière case
    right_max[n - 1] = walls[n - 1]

    # Remplir right_max : max des murs de i à la fin
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculer l'eau retenue à chaque position
    for i in range(n):
        height = min(left_max[i], right_max[i]) - walls[i]
        water += max(0, height)  # Ajouter si positif

    return water  # Retourner le total
