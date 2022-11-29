#ifndef __BOT_H
#define __BOT_H

#include "usefull.h"
//#include "jeu.h"
//#include "neurone.h"

#define NB_NEURONES 8
#define NB_POIDS 38
#define PROFONDEUR 7

class Bot : public Jeu, public Neurones
{
private:
	Jeu g;												//jeu (move,score,lose,matrix)
	Jeu matj[PROFONDEUR][Puiss(4, PROFONDEUR)];	 		//matrice de jeu (move,score,lose,matrix)
	int scores[100];									//tableau des scores obtenus par le bot (après les parties effectuées)
	char bpoids[NB_POIDS];								//poids de chaque neurone
	Neurones ne;

public:
	Bot();

	void Bot_Show();
	void Bot_Play();
	void Bot_Move();
	//void Eval_Grid(Jeu je);

};

#endif 
