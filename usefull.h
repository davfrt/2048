#ifndef __USEFULL_H
#define __USEFULL_H


/*
resumer: rend la puissance b ième de a
prend en entré:
-a (double)
-b (double)
rend en sortie la puissance (double)
*/
unsigned short Puiss(unsigned char a, unsigned char b);

/*
resumer: rend la plus petite valeur d'un tableau de valeurs
prend en entré:
-le tableau de valeurs (double)
-la taille du tableau (double)
rend en sortie la valeur min (double)
*/
float Min(float* tab, unsigned char taille);
float Min(float* tab, unsigned short taille);

/*
resumer: rend la plus grande valeur d'un tableau de valeurs
prend en entré:
-le tableau de valeurs (double)
-la taille du tableau (double)
rend en sortie la valeur max (double)
*/
float Max(float* tab, unsigned char taille);
float Max(float* tab, unsigned short taille);
short Max(short* tab, unsigned char taille);

/*
resumer: fait la moyenne de valeurs dans un tab
prend en entré les valeurs (double)
rend en sortie la moyenne (double)
*/
float Moy(int* tab);
float Moy(float* tab);
clock_t Moy(clock_t* tab);

/*
resumer: remet toutes les valeurs d'un tab à zéro
prend en entré:
-un tab (double)
-la taille du tab (double)
rend en sortie un void
*/
void Raztab(float* tab, unsigned char taille);
void Raztab(float* tab, unsigned short taille);

/*
resumer: remet toutes les valeurs d'un tab à zéro
prend en entré:
-un tab (int)
-la taille du tab (int)
rend en sortie un void
*/
void Raztab(int* tab, unsigned char taille);
void Raztab(int* tab, unsigned short taille);

/*
resumer: tri les valeurs d'un tableau de la plus petite à la plus grande
prend en entré:
-un tab (int)
-la taille du tab (int)
rend en sortie un void
*/
void triabul(float* tab, unsigned char taille);
void triabul(float* tab, unsigned short taille);

#endif
