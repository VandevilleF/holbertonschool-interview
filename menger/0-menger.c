#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * check_char - Détermine si une case doit être vide ou remplie
 * @row: Indice de la ligne
 * @col: Indice de la colonne
 *
 * Return: '#' ou ' '
 */
char check_char(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return ' ';
		row /= 3;
		col /= 3;
	}
	return ('#');
}

/**
 * menger - Affiche un Menger Sponge de niveau donné
 * @level: Niveau de récursion
 */
void menger(int level)
{
	if (level < 0)
		return;

	int size = pow(3, level);

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			putchar(check_char(row, col));
		}
		putchar('\n');
	}
}
