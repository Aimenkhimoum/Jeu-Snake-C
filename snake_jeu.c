#include "snake.h"

int main() {
    srand(time(NULL));

    //  INITIALISATION POUR AFFICHAGE AVEC NCURSES
    initscr();              // pour démarrer le mode ncurses
    cbreak();               // désactive le buffer de ligne
    noecho();               // ne pas afficher les touches pressées
    keypad(stdscr, TRUE);   // activer les touches spéciales (les flèches)
    nodelay(stdscr, TRUE);  // getch() ne bloque pas le programme 
    curs_set(0);            // cache le curseur clignotant

    //initialisation des couleurs des éléments
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_BLACK);  // murs
        init_pair(2, COLOR_RED, COLOR_BLACK);   // fruit
        init_pair(3, COLOR_GREEN, COLOR_BLACK); // serpent
    }

    //  INITIALISATION JEU 
    int lignes = 20, colonnes = 40;
    Grille *gr = grille_creer(lignes, colonnes);
    grille_initialiser(gr);

    // position de départ du snake au centre de la grille
    int startX = lignes / 2;
    int startY = colonnes / 2;
    
    Snake *snake = snake_creer(startX, startY);
    Direction dir = DROITE;
    placer_fruit_alea(gr);

    int game_over = 0;
    int ch;
    int score = 0;

    // la boucle de jeu principale
    while (!game_over) {
        // gestion des entrées (flèches pour diriger le snake, Q pour quitter)
        ch = getch();
        switch (ch) {
            case KEY_UP:    if(dir != BAS) dir = HAUT; break;
            case KEY_DOWN:  if(dir != HAUT) dir = BAS; break;
            case KEY_LEFT:  if(dir != DROITE) dir = GAUCHE; break;
            case KEY_RIGHT: if(dir != GAUCHE) dir = DROITE; break;
            case 'q':       game_over = 1; break;
        }

        // calcul de la nouvelle position
        int nx = snake->tete->x;
        int ny = snake->tete->y;

        if (dir == HAUT) nx--;
        if (dir == BAS) nx++;
        if (dir == GAUCHE) ny--;
        if (dir == DROITE) ny++;

        // vérifier les collisions
          if (verifier_collision(gr, nx, ny)) {
            game_over = 1;
        }
        
        // collision avec soi-même (on parcourt le corps)
        Corps *temp = snake->tete;
        while(temp) {
            if (temp->x == nx && temp->y == ny) {
                game_over = 1;
            }
            temp = temp->suivant;
        }

        if (game_over) break;

        // déplacer le snake (ajouter une tête à la nouvelle position)
        snake_ajouter_tete(snake, nx, ny);

        if (gr->tab[nx][ny] == FRUIT) {
            score += 10;
            gr->tab[nx][ny] = VIDE; // si on mange le fruit
            placer_fruit_alea(gr);
            // on ne supprime pas la queue du snake si il mange le fruit, donc il grandit
        } else {
            snake_supprimer_queue(snake); // Il avance simplement
        }

        // affichage
        afficher_grille_ncurses(gr, snake, score);

        // contrôle de la vitesse du jeu
        napms(100); // pause en millisecondes 100ms 
    }

    // fin du jeu
    nodelay(stdscr, FALSE); // on repasse en mode bloquant pour attendre une touche
    mvprintw(lignes/2, (colonnes/2)-5, "GAME OVER :( !");
    mvprintw((lignes/2)+1, (colonnes/2)-8, "Pressez une touche pour quitter");
    refresh();
    getch();

    // NETTOYAGE
    endwin();  // quitter le mode ncurses proprement
    liberer_snake(snake);
    grille_desallouer(gr);

    return 0;
}