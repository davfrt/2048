#include "jeu.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <random>
#include <time.h>
#include "bot.h"
#include "neurone.h"
#include "usefull.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

#define PROFONDEUR 7
#define NB_NEURONES 8
#define NB_POIDS 38
#define NB_EVAL 20

static char i = 0, j = 0, k = 0, l = 0, index;
static bool different;
static unsigned short matrice[4][4], max;
static int tabval[4], z;
static Jeu tabjeu[30];

Bot::Bot():g(), ne(bpoids)
{
	for (i = 0; i < NB_POIDS; ++i)
	{
		if (rand() % 2 == 0) { bpoids[i] = rand() % 40 - 20; }
		else { bpoids[i] = rand() % 200 - 100; }
	}

	for (i = 0; i < 100; ++i) { scores[i] = 0; }

	for (i = 0; i < PROFONDEUR; ++i)
	{
		for (z = 0; z < Puiss(4, i); ++z) { matj[i][z](); }
	}

}

void Bot::Bot_Show()
{
	g.Reinit_Jeu();
	g.Print_Grid();

	// boucle de jeu
	while (g.Get_Lose() == false)
	{
		Bot_Move();
		g.Next_Move();
		g.Print_Grid();
		std::cout << "\n\n score: " << g.Get_Score();
		Sleep(300);
	}
	//
}

void Bot::Bot_Play()
{
	g.Reinit_Jeu();

	// boucle de jeu
	while (g.Get_Lose() == false)
	{
		Bot_Move();
		g.Next_Move();
	}
	//

	i = 0;
	while (scores[i] != 0) { ++i; }

	scores[i] = g.Get_Score();

	g.Get_Score() = 0;
}

void Bot::Bot_Move()
{
	different = false;

	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j) { matrice[i][j] = g.Get_Matrix_Value(i, j); }
	}

	matj[0][0](g);

	for (i = 1; i <= PROFONDEUR; ++i)				//profondeur - 1
	{
		for (z = 0; z < Puiss(4, i); ++z)
		{

			matj[i][z](matj[i - 1][z / 4]);

			switch (z % 4)
			{
			case 0:
				matj[i][z].move = 'z';
				matj[i][z].value = ne.Get_Value(matj[i][z]);
				break;
			case 1:
				matj[i][z].move = 'q';
				matj[i][z].value = ne.Get_Value(matj[i][z]);
				break;
			case 2:
				matj[i][z].move = 's';
				matj[i][z].value = ne.Get_Value(matj[i][z]);
				break;
			case 3:
				matj[i][z].move = 'd';
				matj[i][z].value = ne.Get_Value(matj[i][z]);
				break;
			}
		}
	}

	//for (int i = 0; i < puiss(4, profondeur(b->poids[6])); i++)
	//		gridnextmove(b, b->matj[profondeur(b->poids[6])-2][i]);

	for (i = PROFONDEUR; i > 1; --i)		//profondeur - 2
	{
		for (z = 0; z < Puiss(4, i); ++z)
		{
			tabval[z % 4] = matj[i][j].value;
			if ((z % 4) == 3) { matj[i - 1][z / 4].value = Max(tabval, 4); }
		}
	}

	while (different == false)
	{
		max = -30000;
		for (i = 0; i < 4; ++i)
		{
			if (matj[1][i].value > max)
			{
				max = matj[1][i]->value;
				index = i;
			}
			//printf("\n\nvalue[%d] %lf\n\n", i, b->matj[1][i]->value);
		}
		//Sleep(600);

		switch (index)
		{
		case 0:
			g.move = 'z';
			break;
		case 1:
			g.move = 'q';
			break;
		case 2:
			g.move = 's';
			break;
		case 3:
			g.move = 'd';
			break;
		}

		//getjeu(a, b->j);
		matj[0][1](g);
		matj[0][1].Next_Move();

		//printf("\n\nmove %c\n\n", b->j->move);
		//printgrid(*a->matrix);
		//printgrid(*b->j->matrix);
		//Sleep(600);

		for (i = 0; i < 4; ++i)
		{
			for (j = 0; j < 4; ++j)
			{
				if (matrice[i][j] != matj[0][1].Get_Matrix_value(i, j)) { different = true; break; break; }
			}
		}

		if (different == false) { matj[1][index].value = -30000; }
		//Sleep(600);
	}
}
