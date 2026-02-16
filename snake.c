#include "snake.h"

//  LA GESTION DE LA GRILLE

Grille* grille_creer(int n, int m) {
    Grille *g = malloc(sizeof(Grille));
    g->n = n;
    g->m = m;
    g->tab = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->tab[i] = malloc(m * sizeof(int));
    }
    return g;
}

void grille_initialiser(Grille *g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->m; j++) {
            //création des murs sur les bords
            if (i == 0 || i == g->n - 1 || j == 0 || j == g->m - 1)
                g->tab[i][j] = MUR;
            else
                g->tab[i][j] = VIDE;
        }
    }
}

void grille_desallouer(Grille *g) {
    for (int i = 0; i < g->n; i++) {
        free(g->tab[i]);
    }
    free(g->tab);
    free(g);
}

void placer_fruit_alea(Grille *g) {
    int x, y;
    do {
        x = rand() % (g->n - 2) + 1; // pour éviter les murs (bords)
        y = rand() % (g->m - 2) + 1;
    } while (g->tab[x][y] != VIDE);
    g->tab[x][y] = FRUIT;
}

// LA GESTION DU SNAKE 

Snake* snake_creer(int x, int y) {
    Snake *s = malloc(sizeof(Snake));
    Corps *c = malloc(sizeof(Corps));
    c->x = x;
    c->y = y;
    c->suivant = NULL;
    s->tete = c;
    s->longueur = 1;
    return s;
}

void snake_ajouter_tete(Snake *s, int x, int y) {
    Corps *nv = malloc(sizeof(Corps));
    nv->x = x;
    nv->y = y;
    nv->suivant = s->tete;
    s->tete = nv;
    s->longueur++;
}

void snake_supprimer_queue(Snake *s) {
    if (s->tete == NULL) return;
    
    // si le serpent n'a qu'un seul élément (que la tête), on ne fait rien
    if (s->tete->suivant == NULL) return;

    Corps *actuel = s->tete;
    // on va jusqu'à l'avant-dernier élément
    while (actuel->suivant && actuel->suivant->suivant) {
        actuel = actuel->suivant;
    }
    // on supprime le dernier
    free(actuel->suivant);
    actuel->suivant = NULL;
}

int verifier_collision(Grille *g, int x, int y) {
    // collision avec un mur
    if (g->tab[x][y] == MUR) return 1;
    return 0;
}
//fonction pour libérer la mémoire du snake
void liberer_snake(Snake *s) {
    Corps *c = s->tete;
    while (c) {
        Corps *temp = c;
        c = c->suivant;
        free(temp);
    }
    free(s);
}

// AFFICHAGE 

void afficher_grille_ncurses(Grille *g, Snake *s, int score) {
    clear(); // pour effacer l'écran 
    
    // on dessine la grille statique (murs et fruit)
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->m; j++) {
            // mvprintw(ligne, colonne, "le caractère");
            if (g->tab[i][j] == MUR) {
                attron(COLOR_PAIR(1)); // couleur murs
                mvprintw(i, j, "+");
                attroff(COLOR_PAIR(1));
            } else if (g->tab[i][j] == FRUIT) {
                attron(COLOR_PAIR(2)); // couleur fruit
                mvprintw(i, j, "*");
                attroff(COLOR_PAIR(2));
            }
        }
    }

    // on dessine le snake par dessus
    Corps *c = s->tete;
    while(c) {
        attron(COLOR_PAIR(3)); // couleur serpent
        mvprintw(c->x, c->y, "o");
        attroff(COLOR_PAIR(3));
        c = c->suivant;
    }

    // pour afficher le score
    mvprintw(g->n + 1, 0, "Score : %d  (Q pour quitter)", score);
    refresh(); // actualiser l'écran réel
}