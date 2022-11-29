//#include "game.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <random>
#include <time.h>
//#include "bot.h"
#include "neurone.h"
#include "usefull.h"
#pragma warning( disable : 4430 )

#define NB_NEURONES 8
#define NB_POIDS 38

static bool ok, threetime, in_grid;
static char index, index1, index2, i, j, k, l, m, nbcolone, count, a, nmbr, diff;
static unsigned short max, max1, max2;
static short value;
//int somme;

Neurones::Neurones(char* tab) 
{
	for (i = 0; i < NB_POIDS; ++i) { poids[i] = tab[i]; }
}

short Neurones::Get_Value(Jeu const ge)
{
	j(ge);
	value = 0;
	value += Corner();
	value += Colone();
	value += Zeros();
	value += Middle();
	value += Lose();
	value += No_match_high();
	value += No_match_low();
	value += Near();
	return value;
}

char Neurones::Corner() // poids[0]
{
	max = 0; l = 0;

	for (i = 0; i < 4; ++i)
	{
		for (k = 0; k < 4; ++k)
		{
			if (j.Get_Matrix_Value(i, k) > max)
			{
				max = j.Get_Matrix_Value(i, k);
				index1 = i;
				index2 = k;
			}
		}
	}

	for (i = 0; i < 4; ++i)
	{
		for (k = 0; k < 4; ++k)
		{
			if (j.Get_Matrix_Value(i, k) == max && (i != index1 || k != index2))
			{
				++l;
				if (l == 2) { return poids[1]; } //faux
			}
		}
	}


	if (max == j.Get_Matrix_Value(0, 0) || max == j.Get_Matrix_Value(0, 3) || max == j.Get_Matrix_Value(3, 0) || max == j.Get_Matrix_Value(3, 3)) { return poids[0]; }//vrai

	return poids[1];			//faux
}

char Neurones::Colone()	// poids[1]
{
	ok = false;
	nbcolone = 0;
	max = 0;

	if (Corner() != poids[1])
	{
		for (i = 0; i < 4; ++i)
		{
			for (k = 0; k < 4; ++k)
			{
				if (max < j.Get_Matrix_Value(i, k))
					max = j.Get_Matrix_Value(i, k);
			}
		}

		if (j.Get_Matrix_Value(0, 0) != j.Get_Matrix_Value(0, 1) && j.Get_Matrix_Value(0, 1) != j.Get_Matrix_Value(0, 2) && j.Get_Matrix_Value(0, 2) != j.Get_Matrix_Value(0, 3) && (max == j.Get_Matrix_Value(0, 0) || max == j.Get_Matrix_Value(0, 3)))
		{
			return poids[2];
		}

		if (j.Get_Matrix_Value(0, 0) != j.Get_Matrix_Value(1, 0) && j.Get_Matrix_Value(1, 0) != j.Get_Matrix_Value(2, 0) && j.Get_Matrix_Value(2, 0) != j.Get_Matrix_Value(3, 0) && (max == j.Get_Matrix_Value(0, 0) || max == j.Get_Matrix_Value(3, 0)))
		{
			return poids[2];
		}
		if (j.Get_Matrix_Value(0, 3) != j.Get_Matrix_Value(1, 3) && j.Get_Matrix_Value(1, 3) != j.Get_Matrix_Value(2, 3) && j.Get_Matrix_Value(2, 3) != j.Get_Matrix_Value(3, 3) && (max == j.Get_Matrix_Value(0, 3) || max == j.Get_Matrix_Value(3, 3)))
		{
			return poids[2];
		}
		if (j.Get_Matrix_Value(3, 0) != j.Get_Matrix_Value(3, 1) && j.Get_Matrix_Value(3, 1) != j.Get_Matrix_Value(3, 2) && j.Get_Matrix_Value(3, 2) != j.Get_Matrix_Value(3, 3) && (max == j.Get_Matrix_Value(3, 0) || max == j.Get_Matrix_Value(3, 3)))
		{
			return poids[2];
		}
	}
	return poids[3];
}

char Neurones::Zeros() // poids[2]
{
	l = 0; //nombre de zeros
	for (i = 0; i < 4; ++i)
	{
		for (k = 0; k < 4; ++k)
		{
			if (j.Get_Matrix_Value(i, k) == 0)
				++l;
		}
	}


	switch (l)
	{
	case 0:
		return poids[4]; break;
	case 1:
		return poids[5]; break;
	case 2:
		return poids[6]; break;
	case 3:
		return poids[7]; break;
	case 4:
		return poids[8]; break;
	case 5:
		return poids[9]; break;
	case 6:
		return poids[10]; break;
	case 7:
		return poids[11]; break;
	case 8:
		return poids[12]; break;
	case 9:
		return poids[13]; break;
	case 10:
		return poids[14]; break;
	case 11:
		return poids[15]; break;
	default:
		return poids[16]; break;
	
	}

}


char Neurones::Middle()	//	poids[3]
{
	max = 0;

	for (i = 0; i < 4; ++i)
	{
		for (k = 0; k < 4; ++k)
		{
			if (j.Get_Matrix_Value(i, k) > max)
			{
				max = j.Get_Matrix_Value(i, k);
			}
		}
	}


	if (max == j.Get_Matrix_Value(1, 1) || max == j.Get_Matrix_Value(1, 2) || max == j.Get_Matrix_Value(2, 1) || max == j.Get_Matrix_Value(2, 2))
		return poids[18];
	else
		return poids[17];
}

char Neurones::Lose()	//	poids[4]
{
	if (j.Get_Lose() == true)
		return poids[20];
	return poids[19];
}

char Neurones::No_match_high()	//	poids[5]
{
	max = 0;

	for (i = 0; i < 4; ++i)
	{
		for (k = 0; k < 4; ++k)
		{
			if (j.Get_Matrix_Value(i, k) > max)
			{
				max = j.Get_Matrix_Value(i, k);
			}
		}
	}

	for (a = 1; a < 3; ++a)
	{
		count = 0;
		for (i = 0; i < 4; ++i)
		{
			for (k = 0; k < 4; ++k)
			{
				if (j.Get_Matrix_Value(i, k) == (max / a))
					++count;
				if (count == 2)
					return poids[22];
			}
		}
	}
	return poids[21];
}

char Neurones::No_match_low()	//	poids[6]
{
	value = 8; max = 0;
	threetime = false;

	for (i = 0; i < 4; ++i)
	{
		for (int k = 0; k < 4; k++)
		{
			if (j.Get_Matrix_Value(i, k) > max)
			{
				max = j.Get_Matrix_Value(i, k);
			}
		}
	}

	while (value <= (max / 4))
	{
		count = 0;
		for (i = 0; i < 4; ++i)
		{
			for (k = 0; k < 4; ++k)
			{
				if (value == j.Get_Matrix_Value(i, k))
					++count;
			}
		}
	
		if (count > 3)
			return poids[25];

		if (count == 3)
			threetime = true;

		value *= 2;
	}

	if (threetime == true)
		return poids[23];
	else
		return poids[24];

}

char Neurones::Near() // poids[7]
{
	if (Colone() != 0)
	{
		max1 = 0; max2 = 0; diff = 1; nmbr = 0; index = 1;
		in_grid = false;

		while (diff == 1)
		{
			if (index == 1)
			{
				for (i = 0; i < 4; ++i)
				{
					for (k = 0; k < 4; ++k)
					{
						if (max1 > j.Get_Matrix_Value(i, k))
						{
							max1 = j.Get_Matrix_Value(i, k);
							index1 = i;
							index2 = k;
						}
					}
				}
			}
			else if (max1 > 4)
			{
				in_grid = false;
				while (in_grid == false)
				{
					max1 *= 0.5;
					count = 0;
					for (i = 0; i < 4; ++i)
					{
						for (k = 0; k < 4; ++k)
						{
							if (max1 == j.Get_Matrix_Value(i, k))
							{
								max1 = j.Get_Matrix_Value(i, k);
								index1 = i;
								index2 = k;
								++count;
								in_grid = true;
							}
							if (count > 1)
							{
								break;
								break;
								break;
								break;
							}
						}
					}
				}
			}
			else
				break;

			for (i = 0; i < 4; ++i)
			{
				for (k = 0; k < 4; ++k)
				{
					if (max2 > j.Get_Matrix_Value(i, k) && max2 < max1)
					{
						max2 = j.Get_Matrix_Value(i, k);
						diff = abs(i - index1) + abs(k - index2);
					}
				}
			}

			if (diff == 1)
				++nmbr;
			++index;
		}

		switch (nmbr)
		{
		case 0:
			return poids[37]; break;
		case 1:					//////////// 
			return poids[26]; break;
		case 2:
			return poids[27]; break;
		case 3:
			return poids[28]; break;
		case 4:
			return poids[29]; break;
		case 5:
			return poids[30]; break;
		case 6:
			return poids[31]; break;
		case 7:
			return poids[32]; break;
		case 8:
			return poids[33]; break;
		case 9:
			return poids[34]; break;
		case 10:
			return poids[35]; break;
		default:
			return poids[36];
			break;
		}

	}
	return poids[37];
}



//PAS DES NEURONES MAIS TRES UTILE


/*
int nbrtabcompar()	//	 poids[on s'en tape]
{
	//return(int(30 * poids + 10));
	return(20);
}


int profondeur()	//	 poids[on s'en tape]
{
	//return(int(15 * poids));
	return(5);
}
*/


