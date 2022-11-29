//#include "jeu.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <random>
#include <time.h>
//#include "bot.h"
//#include "neurone.h"
#include "usefull.h"
#include <ctime>

//namespace Var
//{
static char v = 0, w = 0, k = 0, l = 0;
//}


//using namespace Var;

unsigned short Puiss(unsigned char a, unsigned char b)
{
	unsigned short result = a;

	if (b == 0)
		return 1;

	for (v = 1; v < b; ++v)
		result *= a;

	return result;
}

float Min(float* tab, unsigned char taille)
{
	float min = tab[0];
	for (v = 0; v < taille; ++v)
	{
		if (tab[v] < min)
			min = tab[v];
	}
	return min;
}

float Min(float* tab, unsigned short taille)
{
	float min = tab[0];
	for (v = 0; v < taille; ++v)
	{
		if (tab[v] < min)
			min = tab[v];
	}
	return min;
}

float Max(float* tab, unsigned char taille)
{
	float max = 0.0;
	for (v = 0; v < taille; ++v)
	{
		//printf("\n\n%lf tab \n\n", tab[v]);
		if (tab[v] > max)
			max = tab[v];
	}
	//printf("\n\n%lf max \n\n", max);
	return max;
}

float Max(float* tab, unsigned short taille)
{
	float max = 0.0;
	for (v = 0; v < taille; ++v)
	{
		//printf("\n\n%lf tab \n\n", tab[v]);
		if (tab[v] > max)
			max = tab[v];
	}
	//printf("\n\n%lf max \n\n", max);
	return max;
}

short Max(short* tab, unsigned char taille)
{
	short max = 0;
	for (v = 0; v < taille; ++v)
	{
		//printf("\n\n%lf tab \n\n", tab[v]);
		if (tab[v] > max)
			max = tab[v];
	}
	//printf("\n\n%lf max \n\n", max);
	return max;
}

float Moy(int* tab)
{
	v = 0;
	float somme = 0.0;
	//printf("\n\n");
	while (tab[v] != 0)
	{
		//printf("\n %lf: \n", tab[l]);
		somme += tab[v];
		++v;
	}
	//printf("\n\nl: %d\n\n", l);
	return somme / v;
}

float Moy(float* tab)
{
	v = 0;
	float somme = 0.0;
	//printf("\n\n");
	while (tab[v] != 0)
	{
		//printf("\n %lf: \n", tab[l]);
		somme += tab[v];
		++v;
	}
	//printf("\n\nl: %d\n\n", l);
	return somme / v;
}

clock_t Moy(clock_t* tab)
{
	v = 0;
	clock_t somme = 0.0;
	//printf("\n\n");
	while (tab[v] != 0)
	{
		//printf("\n %lf: \n", tab[l]);
		somme += tab[v];
		++v;
	}
	//printf("\n\nl: %d\n\n", l);
	return somme / v;
}

void Raztab(float* tab, unsigned char taille)
{
	for (v = 0; v < taille; ++v)
		tab[v] = 0;
}

void Raztab(float* tab, unsigned short taille)
{
	for (v = 0; v < taille; ++v)
		tab[v] = 0;
}

void Raztab(int* tab, unsigned char taille)
{
	for (v = 0; v < taille; ++v)
		tab[v] = 0;
}

void Raztab(int* tab, unsigned short taille)
{
	for (v = 0; v < taille; ++v)
		tab[v] = 0;
}


void triabul(float* tab, unsigned char taille)
{
	float swap, max;
	for (v = 0; v < taille; ++v)
	{
		max = -1.0;		//tab de valeurs positives
		for (w = 0; w < (taille - v); ++w)
		{
			if (tab[w] > max)
			{
				max = tab[w];
				k = w;						// k un index 
			}
		}

		swap = tab[taille - v - 1];
		tab[taille - v - 1] = max;
		tab[k] = swap;
	}
}

void triabul(float* tab, unsigned short taille)
{
	float swap, max;
	for (v = 0; v < taille; ++v)
	{
		max = -1.0;		//tab de valeurs positives
		for (w = 0; w < (taille - v); ++w)
		{
			if (tab[w] > max)
			{
				max = tab[w];
				k = w;						// k un index 
			}
		}

		swap = tab[taille - v - 1];
		tab[taille - v - 1] = max;
		tab[k] = swap;
	}
}