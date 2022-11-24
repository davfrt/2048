#include "jeu.h"
//#include "grid.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <random>
#include <iostream>
#include <time.h>
//#pragma warning( disable : 4996 )

using namespace std;

void Jeu::Game()
{
	//boucle de jeu
	while (lose == false)
	{
		Print_Grid();
		cout << "\n\n score: " << (int)score;
		cout << "\n\nquel est votre coup ? (z,q,s,d)\n";
		move = ' ';
		while (move != 'z' && move != 'q' && move != 's' && move != 'd') { cin >> move; }
		Next_Move();
	}
	//

	Print_Grid();
	cout << "\nvous avez perdu";
	cout << "\nvotre score est de %d\n\n" << score;
}

void Jeu::Reinit_Jeu()
{
	for (char i = 0; i < 4; ++i)
	{
		for (char j = 0; j < 4; ++j) { matrix[i][j] = (unsigned short) 0; }
	}
	char rand1 = rand() % 16, rand2;
	do { rand2 = rand() % 16; } while (rand1 == rand2);
	matrix[rand1 / 4][rand1 % 4] = (unsigned short)(2 * (rand() % 2 + 1));
	matrix[rand2 / 4][rand2 % 4] = (unsigned short)(2 * (rand() % 2 + 1));
	score = 0;
	move = 'a';
	lose = false;
	value = 0;
}

void Jeu::Next_Move()
{
	//initialisation des variables
	unsigned short matrice[4][4];	//matrice (tampon) copiant les valeurs précédentes de la matrice de jeu
	bool different = false;			//bool pour savoir si la matrice précédentes est la même que la suivante
	char i, j, k;
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j)
			matrice[i][j] = matrix[i][j];
	}
	//

	if (move == 'z')		//	haut
	{
		for (k = 0; k < 4; ++k)
		{
			for (i = 1; i < 4; ++i)
			{
				for (j = 0; j < 4; ++j)
				{
					if (matrix[i][j] != 0)
					{
						if (matrix[i - 1][j] == matrix[i][j] && k == 2)
						{
							matrix[i - 1][j] *= 2;
							score += matrix[i][j];
							matrix[i][j] = 0;
						}
						if (matrix[i - 1][j] == 0 and k != 2)
						{
							matrix[i - 1][j] = matrix[i][j];
							matrix[i][j] = 0;
						}
					}
				}
			}
		}
	}

	else if (move == 'q')	//	gauche
	{
		for (k = 0; k < 4; ++k)
		{
			for (i = 0; i < 4; ++i)
			{
				for (j = 1; j < 4; ++j)
				{
					if (matrix[i][j] != 0)
					{
						if (matrix[i][j - 1] == matrix[i][j] && k == 2)
						{
							matrix[i][j - 1] *= 2;
							score += matrix[i][j];
							matrix[i][j] = 0;
						}
						if (matrix[i][j - 1] == 0 && k != 2)
						{
							matrix[i][j - 1] = matrix[i][j];
							matrix[i][j] = 0;
						}
					}
				}
			}
		}
	}

	else if (move == 's')	//	bas
	{
		for (k = 0; k < 4; ++k)
		{
			for (i = 2; i > -1; --i)
			{
				for (j = 0; j < 4; ++j)
				{
					if (matrix[i][j] != 0)
					{
						if (matrix[i + 1][j] == matrix[i][j] && k == 2)
						{
							matrix[i + 1][j] *= 2;
							score += matrix[i][j];
							matrix[i][j] = 0;
						}
						if (matrix[i + 1][j] == 0 && k != 2)
						{
							matrix[i + 1][j] = matrix[i][j];
							matrix[i][j] = 0;
						}
					}
				}
			}
		}
	}

	else	//	droite
	{
		for (k = 0; k < 4; ++k)
		{
			for (i = 0; i < 4; ++i)
			{
				for (j = 2; j > -1; --j)
				{
					if (matrix[i][j] != 0)
					{
						if (matrix[i][j + 1] == matrix[i][j] && k == 2)
						{
							matrix[i][j + 1] *= 2;
							score += matrix[i][j];
							matrix[i][j] = 0;
						}
						if (matrix[i][j + 1] == 0 && k != 2)
						{
							matrix[i][j + 1] = matrix[i][j];
							matrix[i][j] = 0;
						}
					}
				}
			}
		}
	}

	//vérifie si la matrice avant le coup et après le coup son la même
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			if (matrice[i][j] != matrix[i][j])
				different = true;	//booléen si les matrices sont différentes
		}
	}
	//

	//si les matrices sont différentes => ajout d'une valeur (2 ou 4) dans la matrice
	if (different == true)
	{
		char rand0;
		do { rand0 = rand() % 16; } while (matrix[rand0 / 4][rand0 % 4] != 0);
		matrix[rand0 / 4][rand0 % 4] = 2 * (rand() % 2 + 1);
	}
	//

	//vérifie si la partie est perdu
	Lose();
	//
}

void Jeu::Lose()
{
	char i, j;
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (matrix[i][j] == 0)
				return;
			else if (matrix[i][j] == matrix[i][j + 1])
				return;
		}
	}

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			if (matrix[i][j] == 0)
				return;
			else if (matrix[i][j] == matrix[i + 1][j])
				return;
		}
	}

	if (matrix[3][3] == 0)
		return;

	lose = true;
}

void Jeu::Print_Grid() const 
{
	system("cls");
	char maxtaille = Taille(0, 0), i, j;

	//calcul de la taille du plus grand nombre
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			if (Taille(i, j) > maxtaille)
				maxtaille = Taille(i, j);
		}
	}
	//

	//afficage décoratif de la première ligne 
	cout << "+";
	for (i = 0; i < 4; ++i)
	{
		j = 0;
		for (j = 0; j < maxtaille + 1; ++j)
			cout << "-";
	}
	cout << "+\n";
	//

	//affichage de chaque nombre de la matrice
	for (i = 0; i < 4; ++i)
	{
		cout << "|";
		for (j = 0; j < 4; ++j)
		{
			Print_Carac(maxtaille, i, j);
		}
		cout << "|\n";
	}
	//

	//afficage décoratif de la dernière ligne 
	cout << "+";
	for (i = 0; i < 4; ++i)
	{
		j = 0;
		for (j = 0; j < (maxtaille + 1); ++j)
			cout << "-";
	}
	cout << "+\n";
	//
}

char Jeu::Taille(char i0, char j0) const 
{
	unsigned short diviseur = 10;
	char i = 1;
	while ((matrix[i0][j0] % diviseur) != matrix[i0][j0])
	{
		diviseur *= 10;
		++i;
	}
	return i;
}

void Jeu::Print_Carac(char maxlen, char i0, char j0) const
{
	char i;
	if (matrix[i0][j0] != 0)
	{
		for (i = 0; i < (maxlen - Taille(i0, j0) + 1); ++i) { cout << " "; }
		cout << matrix[i0][j0];
	}
	else
	{
		for (i = 0; i < (maxlen + 1); ++i) { cout << " "; }
	}
}

