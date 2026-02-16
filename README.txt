******************* Snake : Le jeu du Serpent ******************** 
******************* Programmeur: KHIMOUM Aimen Mohamed ************
Date:  11/05/2025 

Description du jeu :  
  Le jeu Snake est un grand classique d'arcade où le joueur dirige un serpent qui se déplace sur une grille. 
  Le but est de manger des fruits apparaissant aléatoirement pour grandir et augmenter son score.
  Le défi consiste à ne pas heurter les murs ni sa propre queue au fur et à mesure que le serpent s'allonge.

Installation :  
  Ce jeu a été conçu pour l'environnement Linux et utilise la bibliothèque graphique ncurses.
  Assurez-vous d'avoir installé la librairie nécessaire.
  Dans un terminal, placez-vous dans le répertoire du jeu et utilisez la commande `make` pour compiler le programme.

Comment jouer :  
  Lancer le programme snake_jeu.  
  Sous Linux, utilisez la commande `./snake_jeu`.

  Une fois le jeu lancé, le serpent commence à se déplacer. Le joueur doit le diriger en temps réel.
  Commandes :
  - Flèche HAUT   : Monter
  - Flèche BAS    : Descendre
  - Flèche GAUCHE : Aller à gauche
  - Flèche DROITE : Aller à droite
  - Touche 'Q'    : Quitter la partie en cours

Règles :  
  1. Le serpent ne peut pas s'arrêter, il avance constamment.
  2. Le joueur ne peut pas faire demi-tour immédiat (ex: aller à gauche s'il va à droite).
  3. Le jeu se termine si la tête du serpent heurte un mur (+) ou une partie de son propre corps (o).
  4. Système de points :  
     - Chaque fruit mangé (*) rapporte 10 points au score.
     - Manger un fruit fait grandir le serpent d'une case.

Plaisir d'avoir codé ce jeu :  
  Ce projet m'a permis de travailler la gestion des listes chaînées dynamiques en C, ainsi que la gestion des événements clavier en temps réel.
  L'implémentation de la logique de déplacement et d'affichage fluide a été un défi intéressant.