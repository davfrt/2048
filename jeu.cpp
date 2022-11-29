#include "jeu.h"
#include "usefull.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <random>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <ctime>

//#pragma warning( disable : 4996 )

//namespace Var
//{
//static unsigned char i = 0, j = 0, k = 0;
//}

static char i = 0, j = 0, k = 0, l = 0, sz = 4, plac, rand1, rand2, maxtaille;
static bool modif, conc;
static unsigned short tmp, diviseur;

using namespace std;
//using namespace Var;


	//char i = 0, j = 0, k = 0;
Jeu::Jeu()
{
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j) { matrix[i][j] = 0; }
	}
	rand1 = rand() % 16;
	do { rand2 = rand() % 16; } while (rand1 == rand2);

	if (rand() % 10 == 0) { matrix[rand1 / 4][rand1 % 4] = 4; }
	else { matrix[rand1 / 4][rand1 % 4] = 2; }

	if (rand() % 10 == 0) { matrix[rand2 / 4][rand2 % 4] = 4; }
	else { matrix[rand2 / 4][rand2 % 4] = 2; }
	score = 0;
	move = 'a';
	lose = false;
	value = 0;
}

Jeu::Jeu(unsigned short(*tab)[4], int score0 = 0, char move0 = 'a', bool lose0 = false, short value0 = 0)
{
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j) { matrix[i][j] = tab[i][j]; }
	}
	score = score0;
	move = move0;
	lose = lose0;
	value = value0;
}

Jeu::Jeu(Jeu& const g) :score(g.Get_Score()), move(g.Get_Move()), lose(g.Get_Lose()), value(g.Get_Value())
{
	for (i = 0; i < 4; ++i)
	{
		for (k = 0; k < 4; ++k) { matrix[i][k] = g.Get_Matrix_Value(i ,k); }
	}
}

void Jeu::Game()
{
	//cout << "YOOOOOO1\n";
	//boucle de jeu
	while (lose == false)
	{
		//cout << "YOOOOOO2\n";
		Print_Grid();
		cout << "\n\n score: " << (int)score;
		cout << "\n\nquel est votre coup ? (z,q,s,d)\n";
		move = ' ';
		while (move != 'z' && move != 'q' && move != 's' && move != 'd') { move = _getch(); }
		Next_Move();
	}
	//

	Print_Grid();
	cout << "\nvous avez perdu";
	cout << "\nvotre score est de" << score << "\n\n";
}

void Jeu::Reinit_Jeu()
{
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j) { matrix[i][j] = 0; }
	}
	rand1 = rand() % 16;
	do { rand2 = rand() % 16; } while (rand1 == rand2);
	
	if (rand() % 10 == 0) { matrix[rand1 / 4][rand1 % 4] = 4; }
	else { matrix[rand1 / 4][rand1 % 4] = 2; }

	if (rand() % 10 == 0) { matrix[rand2 / 4][rand2 % 4] = 4; }
	else { matrix[rand2 / 4][rand2 % 4] = 2; }

	score = 0;
	move = 'a';
	lose = false;
	value = 0;
}

/*void Jeu::Next_Move()
{
	//initialisation des variables
	unsigned short matrice[4][4];	//matrice (tampon) copiant les valeurs précédentes de la matrice de jeu
	bool different = false;			//bool pour savoir si la matrice précédentes est la même que la suivante
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
}*/

void Jeu::MovementADroite() {
	modif = false;
	for (j = 0; j < sz; ++j) {
		plac = 0;
		conc = false;
		if (matrix[j][sz - 1]) {
			++plac;
		}
		for (i = 1; i < sz; ++i) {
			if (!matrix[j][sz - 1 - i]) {
			}
			else if (!plac) {
				tmp = matrix[j][sz - 1 - i];
				matrix[j][sz - 1 - i] = 0;
				matrix[j][sz - 1] = tmp;
				++plac;
				modif = true;
			}
			else if (matrix[j][sz - 1 + 1 - plac] == matrix[j][sz - 1 - i] && !conc) {
				conc = true;
				matrix[j][sz - 1 + 1 - plac] *= 2; 
				score += matrix[j][sz - 1 + 1 - plac];
				matrix[j][sz - 1 - i] = 0;
				modif = true;
			}
			else if (sz - 1 - i == plac + 1) {
				conc = false;
				++plac;
			}
			else {
				conc = false;
				tmp = matrix[j][sz - 1 - i];
				matrix[j][sz - 1 - i] = 0;
				matrix[j][sz - 1 - plac] = tmp;
				if (sz - 1 - i != sz - 1 - plac) {
					modif = true;
				}
				++plac;
			}
		}
	}
}

void Jeu::MovementAGauche() {
	modif = false;
	for (j = 0; j < sz; ++j) {
		plac = 0;
		conc = false;
		if (matrix[j][0]) {
			++plac;
		}
		for (i = 1; i < sz; ++i) {
			if (!matrix[j][i]) {
			}
			else if (!plac) {
				tmp = matrix[j][i];
				matrix[j][i] = 0;
				matrix[j][0] = tmp;
				++plac;
				modif = true;
			}
			else if (matrix[j][plac - 1] == matrix[j][i] && !conc) {
				conc = true;
				matrix[j][plac - 1] *= 2;
				score += matrix[j][plac - 1];
				matrix[j][i] = 0;
				modif = true;
			}
			else if (i == plac - 1) {
				conc = false;
				++plac;
			}
			else {
				conc = false;
				tmp = matrix[j][i];
				matrix[j][i] = 0;
				matrix[j][plac] = tmp;
				if (i != plac) {
					modif = true;
				}
				++plac;
			}
		}
	}
}

void Jeu::MovementEnBas() {
	modif = false;
	for (j = 0; j < sz; ++j) {
		plac = 0;
		conc = false;
		if (matrix[sz - 1][j]) {
			++plac;
		}
		for (i = 1; i < sz; ++i) {
			if (!matrix[sz - 1 - i][j]) {
			}
			else if (!plac) {
				tmp = matrix[sz - 1 - i][j];
				matrix[sz - 1 - i][j] = 0;
				matrix[sz - 1][j] = tmp;
				++plac;
				modif = true;
			}
			else if (matrix[sz - plac][j] == matrix[sz - 1 - i][j] && !conc) {
				conc = true;
				matrix[sz - plac][j] *= 2;
				score += matrix[sz - plac][j];
				matrix[sz - 1 - i][j] = 0;
				modif = true;
			}
			else if (sz - 1 - i == plac + 1) {
				conc = false;
				++plac;
			}
			else {
				conc = false;
				tmp = matrix[sz - 1 - i][j];
				matrix[sz - 1 - i][j] = 0;
				matrix[sz - 1 - plac][j] = tmp;
				if (sz - 1 - plac != sz - 1 - i) {
					modif = true;
				}
				++plac;
			}
		}
	}
}

void Jeu::MovementEnHaut() {
	modif = false;
	for (j = 0; j < sz; ++j) {
		plac = 0;
		conc = false;
		if (matrix[0][j]) {
			++plac;
		}
		for (i = 1; i < sz; ++i) {
			if (!matrix[i][j]) {
			}
			else if (!plac) {
				tmp = matrix[i][j];
				matrix[i][j] = 0;
				matrix[0][j] = tmp;
				++plac;
				modif = true;
			}
			else if (matrix[plac - 1][j] == matrix[i][j] && !conc) {
				conc = true;
				matrix[plac - 1][j] *= 2;
				score += matrix[plac - 1][j];
				matrix[i][j] = 0;
				modif = true;
			}
			else if (i == plac) {
				conc = false;
				++plac;
			}
			else {
				conc = false;
				tmp = matrix[i][j];
				matrix[i][j] = 0;
				matrix[plac][j] = tmp;
				if (i != plac) {
					modif = true;
				}
				++plac;
			}
		}
	}
}

void Jeu::Next_Move()
{
	////initialisation des variables
	//unsigned char i, j;

	if (move == 'z')		//	haut
	{
		MovementEnHaut();
	}

	else if (move == 'q')	//	gauche
	{
		MovementAGauche();
	}

	else if (move == 's')	//	bas
	{
		MovementEnBas();
	}

	else if (move == 'd')	//	droite
	{
		MovementADroite();
	}

	//else
	//{
	//	modif = false;
	//}

	//si les matrices sont différentes => ajout d'une valeur (2 ou 4) dans la matrice
	if (modif == true)
	{
		do { rand1 = rand() % 16; } while (matrix[rand1 / 4][rand1 % 4] != 0);
		if(rand() % 10 == 0) { matrix[rand1 / 4][rand1 % 4] = 4; }
		else { matrix[rand1 / 4][rand1 % 4] = 2; }
	}
	//

	//vérifie si la partie est perdu
	Lose();
	//
}

void Jeu::Lose()
{
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
	//cout << "yo3\n";
	maxtaille = Taille(0, 0);

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
	diviseur = 10;
	k = 1;
	while ((matrix[i0][j0] % diviseur) != matrix[i0][j0])
	{
		diviseur *= 10;
		++k;
	}
	//cout << "taille\n";
	return k;
}

void Jeu::Print_Carac(char maxlen, char i0, char j0) const
{
	if (matrix[i0][j0] != 0)
	{
		for (l = 0; l < (maxlen - Taille(i0, j0) + 1); ++l) { cout << " "; }
		cout << matrix[i0][j0];
	}
	else
	{
		for (l = 0; l < (maxlen + 1); ++l) { cout << " "; }
	}
}
