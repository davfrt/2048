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
	char move;						//le dernier coup enregistré (z,q,s,d)
	bool lose;						//savoir si la partie est terminée
	short value;			//valeur empirique de la position permettant de l'évaluer

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
//prend en entrée: une grille de 2048
//rend un void
//*/
//void game();
//
//
///*
//resumer: initialise toute les variables d'une structure jeu à leur état initial
//prend en entré un void
//rend en sortie un jeu
//*/
//jeu* initjeu();
//
///*
//resumer: reinitialise toute les variables d'une structure jeu à leur état initial
//prend en entré un jeu
//rend en sortie un void
//*/
//void reinitjeu(jeu* j);
//
///*
//resumer: réalise les changement nécessaire pour faire un coup
//prend en entré un jeu
//rend en sortie un jeu
//*/
//void nextmove(jeu* g);
//
///*
//resumer: vérifie si la partie est terminer
//prend en entré un jeu
//rend en sortie un void
//*/
//void lose(jeu* g);
//
///*
//resumer: attribue les variables d'un jeu à un autre (donne à j1 les varibles de j2)
//prend en entré un jeu
//rend en sortie un void
//*/
//void getjeu(jeu* j1, jeu* j2);
//
///*
//resumer: libère la mémoire d'une structure jeu
//prend en entré un jeu
//rend en sortie un void
//*/
//void deletegame(jeu* g);

#endif