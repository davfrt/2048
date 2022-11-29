#ifndef __NEURONE_H
#define __NEURONE_H

#include "jeu.h"

#define NB_NEURONES 8
#define NB_POIDS 38

class Neurones
{
private:
	Jeu j;
	char Corner();
	char Colone();
	char Zeros();
	char Middle();
	char Lose();
	char No_match_high();
	char No_match_low();
	char Near();
	char poids[NB_POIDS];

public:

	Neurones(char* tab);

	short Get_Value(Jeu const ge);
};

//
//
///*
//resumer: neurone vérifiant si le plus gros nombre est dans un coin
//prend en entré:
//-un jeu
//-la valeur du poids (float)
//rend en sortie un float
//*/
//float corner(jeu* j, float poids);
//
///*
//resumer: neurone vérifiant si une colonne est réalisée
//prend en entré:
//-un jeu
//-la valeur du poids (float)
//rend en sortie un float
//*/
//float colone(jeu* j, float poids);
//
///*
//resumer: neurone vérifiant le nombre de zeros dans la grille
//prend en entré:
//-un jeu
//-la valeur du poids (float)
//rend en sortie un float
//*/
//float zeros(jeu* j, float poids);
//
///*
//resumer: neurone vérifiant si le nombre max est au centre de la position
//prend en entré:
//-un jeu
//-la valeur du poids (float)
//rend en sortie un float
//*/
//float middle(jeu* j, float poids);
//
///*
//resumer: neurone vérifiant si la partie est perdu
//prend en entré:
//-un jeu
//-la valeur du poids (float)
//rend en sortie un float
//*/
//float lose(jeu* j, float poids);
//
///*
//resumer: neurone vérifiant si les nombres les plus hauts sont matchés ou non
//prend en entré:
//-un jeu
//-la valeur du poids (float)
//rend en sortie un float
//*/
//float no_match_high(jeu* j, float poids);
//
///*
//resumer: neurone vérifiant si les nombres les plus bas sont matchés ou non
//prend en entré:
//-un jeu
//-la valeur du poids (float)
//rend en sortie un float
//*/
//float no_match_low(jeu* j, float poids);
//
///*
//resumer: neurone vérifiant la distance entre le nombre max et le second nombre max
//prend en entré:
//-un jeu
//-la valeur du poids (float)
//rend en sortie un float
//*/
//float Near(jeu* j, float poids);
//
///*
//resumer: neurone vérifiant le nombre de partie à analyser
//prend en entré:
//-la valeur du poids (float)
//-la valeur du poids (float)
//rend en sortie le nombre de matrice de jeu à comparer (int)
//*/
//int nbrtabcompar();
//
///*
//resumer: neurone vérifiant la profondeur de coup à analyser
//prend en entré la valeur du poids (float)
//rend en sortie le nombre de la profondeur de coup (int)
//*/
//int profondeur();

#endif 
