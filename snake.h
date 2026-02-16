#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// définition des éléments de la grille
#define VIDE 0
#define MUR 1
#define SERPENT 2
#define FRUIT 3

// les directions pour le déplacement du snake
typedef enum { HAUT, BAS, GAUCHE, DROITE } Direction;

// structure du corps (liste chainée)
typedef struct Corps {
    int x; // ligne
    int y; // colonne
    struct Corps *suivant;
} Corps;

// structure du Snake
typedef struct {
    Corps *tete;
    int longueur;
} Snake;

// structure de la Grille
typedef struct {
    int n; // lignes
    int m; // colonnes
    int **tab; // matrice
} Grille;

// prototypes des fonctions
Grille* grille_creer(int n, int m);
void grille_desallouer(Grille *g);
void grille_initialiser(Grille *g);
void afficher_grille_ncurses(Grille *g, Snake *s, int score);

Snake* snake_creer(int x, int y);
void snake_ajouter_tete(Snake *s, int x, int y);
void snake_supprimer_queue(Snake *s);
int verifier_collision(Grille *g, int x, int y);
void placer_fruit_alea(Grille *g);
void liberer_snake(Snake *s);

#endif