# Snake : Le jeu du Serpent

**Programmeur :** KHIMOUM Aimen Mohamed  
**Date :** 11/05/2025

---

## Description du jeu
Le jeu **Snake** est un grand classique d'arcade où le joueur dirige un serpent qui se déplace sur une grille. 
Le but est de manger des fruits apparaissant aléatoirement pour grandir et augmenter son score. 
Le défi consiste à ne pas heurter les murs ni sa propre queue au fur et à mesure que le serpent s'allonge.

## Installation
Ce jeu a été conçu pour l'environnement **Linux** et utilise la bibliothèque graphique **ncurses**.

1. **Prérequis :** Assurez-vous d'avoir installé la librairie `ncurses` sur votre système.
2. **Compilation :** Dans un terminal, placez-vous dans le répertoire du projet et utilisez la commande suivante :
 ```bash
make
```

## Comment Jouer

```bash 
./snake_jeu
```

## Commandes
Une fois le jeu lancé, le serpent commence à se déplacer. Utilisez les touches suivantes pour le diriger :

Flèche HAUT : Monter

Flèche BAS : Descendre

Flèche GAUCHE : Aller à gauche

Flèche DROITE : Aller à droite

Touche 'Q' : Quitter la partie en cours

## Règles du jeu

Mouvement continu : Le serpent ne peut pas s'arrêter, il avance constamment.

Interdiction de demi-tour : Le joueur ne peut pas faire de demi-tour immédiat (ex: aller à gauche s'il se déplace déjà vers la droite).

Collision : Le jeu se termine si la tête du serpent heurte un mur (+) ou une partie de son propre corps (o).

Système de points :

Chaque fruit mangé (*) rapporte 10 points.

Manger un fruit fait grandir le serpent d'une case.

## Notes sur le développement 

Ce projet m'a permis de mettre en pratique des concepts clés de la programmation en C :

Gestion des listes chaînées dynamiques pour le corps du serpent.

Gestion des événements clavier en temps réel avec ncurses.

Implémentation d'une logique de déplacement et d'affichage fluide.

