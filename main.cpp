#include <stdio.h>
#include "jeu.h"
#include <stdlib.h>
#include <string.h>
//#include "grid.h"
//#include "usefull.h"
//#include "bot.h"
//#include "training.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <iostream>
//#include "neurone.h"
#pragma warning( disable : 4430 )

using namespace std;

//void test1()
//{
//	unsigned short matrice[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
//	jeu game(matrice);
//	std::cout << "\n";
//	for (int i = 0; i < 4; ++i)
//	{
//		for (int j = 0; j < 4; ++j) { std::cout << game.Get_Matrix_Value(i, j); }
//	}
//	std::cout << "\n";
//}


int main()
{
	//test1();
	//pour utiliser le random
	srand(time(NULL));
	//
	//cout << "yo0\n";
	Jeu g;
	g.Game();
	
	return 0;
}

