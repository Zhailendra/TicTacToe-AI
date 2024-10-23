# TicTacToe-AI

## Description

**TicTacToe-AI** est un jeu de morpion (tic-tac-toe) où vous affrontez une intelligence artificielle (IA) qui utilise l'algorithme **Minimax** pour déterminer ses meilleurs coups. L'objectif est de rendre l'IA imbattable tout en offrant une expérience de jeu simple et interactive.

### Fonctionnalités
- Jouer contre une IA qui évalue les mouvements pour maximiser ses chances de gagner.
- Interface de jeu en console où vous entrez vos coordonnées pour placer vos symboles.
- Implémentation du célèbre algorithme Minimax pour la prise de décision de l'IA.
- Gestion des conditions de victoire, défaite et match nul.

## Comment jouer

1. Clonez ce projet sur votre machine locale.
    ```bash
    git clone https://github.com/Zhailendra/TicTacToe-AI.git
    ```

2. Compilez le projet avec un compilateur **C++**. Ou direction avec `build.sh` :
    ```bash
    ./build.sh
    ```

3. Exécutez le programme.
    ```bash
    ./tic-tac-toe-AI
    ```

4. Le jeu se joue dans la console. À chaque tour, le joueur **X** ou **O** entre les coordonnées (x, y) du plateau où il souhaite jouer, avec des valeurs entre 0 et 2.

   Exemple : Player X, enter x and y coordinates (0-2): 1 1


5. L'IA calculera son coup et jouera automatiquement après chaque tour du joueur.

### Règles du Jeu
- Le plateau est une grille de 3x3 cases.
- Le premier joueur (joueur X) commence, suivi du joueur O ou de l'IA.
- Le but est d'aligner trois symboles (X ou O) horizontalement, verticalement ou en diagonale.
- Si toutes les cases sont remplies sans qu'il y ait d'alignement, la partie se termine par un match nul.

## Structure du projet

- **AI.cpp** : Contient l'implémentation de l'intelligence artificielle et l'algorithme Minimax.
- **Player.cpp** : Gère les actions des joueurs (humains ou IA).
- **Game.cpp** : Contient la logique principale du jeu.
- **main.cpp** : Point d'entrée du programme.

## Algorithme Minimax

L'algorithme Minimax est utilisé par l'IA pour prendre des décisions optimales dans un environnement à deux joueurs. L'IA cherche à maximiser son propre score tout en minimisant celui de son adversaire. À chaque étape, elle évalue le plateau pour déterminer le meilleur coup possible.

[Minimax Algorithm in Game Theory](https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-1-introduction/)

## Contributeurs

- [Zhailendra](https://github.com/Zhailendra)

