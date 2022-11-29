#ifndef __JEU_H
#define __JEU_H


//#include "usefull.h"
//#include <random>
#include <ctime>

class Jeu
{
protected:
	unsigned short  matrix[4][4];	//matrice de jeu 2048
	int score;						//le score de la partie
	char move;						//le dernier coup enregistr� (z,q,s,d)
	bool lose;						//savoir si la partie est termin�e
	short value;			//valeur empirique de la position permettant de l'�valuer

	char Taille(char i0, char j0) const;
	void Print_Carac(char maxlen, char i0, char j0) const;
	void Lose();

public:

	Jeu();

	Jeu(unsigned short(*tab)[4], int score0, char move0, bool lose0, short value0);

	Jeu(Jeu& const g); //:score(g.score), move(g.move), lose(g.lose), value(g.value);

	void Reinit_Jeu();
	void Next_Move();

	unsigned short Get_Matrix_Value(unsigned char i0, unsigned char j0) const { return matrix[i0][j0]; }
	int Get_Score() const { return score; }
	char Get_Move() const { return move; }
	bool Get_Lose() const { return lose; }
	short Get_Value() const { return value; }
	
	void Game();
	void Print_Grid() const;

	void MovementADroite();
	void MovementAGauche();
	void MovementEnBas();
	void MovementEnHaut();


};


//
///*
//resumer: lance une partie
//prend en entr�e: une grille de 2048
//rend un void
//*/
//void game();
//
//
///*
//resumer: initialise toute les variables d'une structure jeu � leur �tat initial
//prend en entr� un void
//rend en sortie un jeu
//*/
//jeu* initjeu();
//
///*
//resumer: reinitialise toute les variables d'une structure jeu � leur �tat initial
//prend en entr� un jeu
//rend en sortie un void
//*/
//void reinitjeu(jeu* j);
//
///*
//resumer: r�alise les changement n�cessaire pour faire un coup
//prend en entr� un jeu
//rend en sortie un jeu
//*/
//void nextmove(jeu* g);
//
///*
//resumer: v�rifie si la partie est terminer
//prend en entr� un jeu
//rend en sortie un void
//*/
//void lose(jeu* g);
//
///*
//resumer: attribue les variables d'un jeu � un autre (donne � j1 les varibles de j2)
//prend en entr� un jeu
//rend en sortie un void
//*/
//void getjeu(jeu* j1, jeu* j2);
//
///*
//resumer: lib�re la m�moire d'une structure jeu
//prend en entr� un jeu
//rend en sortie un void
//*/
//void deletegame(jeu* g);

#endif