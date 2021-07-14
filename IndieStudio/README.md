<div align="center"><h1>Indie Studio - Epitech 2021</h1>

L'Indie Studio est un projet est un projet graphique de 1 mois réalisé par 6 étudiants à [Epitech Paris](https://www.epitech.eu/fr/)

[Steven Zheng](https://github.com/stevenZ4), 
[Vincent Cadoz](https://github.com/vcadoz),
[Alexandre Viry](https://github.com/AlexandreViry),
[Matteo Theboul](https://github.com/MTheboul),
[Pierre Aillet](https://github.com/Pierre570),
[Alexis Guerquin](https://github.com/aguerquin).

<img src="https://cdn03.nintendo-europe.com/media/images/10_share_images/games_15/nintendo_switch_4/H2x1_NSwitch_SuperBombermanR.jpg" alt="Indie studio" /></div>

## Projet Indie Studio

### Librairies

Le bomberman fonctionne avec la bibliothèque Raylib

- [Raylib](https://www.raylib.com/)

## Installation et compilation

### Récupération du projet

Après avoir cloné le [répertoire](https://github.com/EpitechIT2020/B-YEP-400-PAR-4-1-indiestudio-steven.zheng.git):

```
git clone https://github.com/EpitechIT2020/B-YEP-400-PAR-4-1-indiestudio-steven.zheng.git
```

- Se rendre à la racine du projet :

```
$ cd B-YEP-400-PAR-4-1-indiestudio-steven.zheng/
```

- Vérifier que tout est à jour :

```
$ git checkout master
```

### Compilation du programme

- Génération du Makefile

```
$ mkdir build
$ cd build
$ cmake ..
```

- Compilation

```
$ cd build
$ make
```


## Execution

### Lancement du programme

```
$ ./bomberman
```

## Touches

| Action                | Touches |  Touches  |  Touches  |  Touches  |
|                       | joueur 1|  joueur 2 |  joueur 3 |  joueur 4 |
| --------------------- |:-------:|:---------:|:---------:|:---------:|
| Avancer               |    z    |  *F haut  |     i     |   *PN 8   |
| Reculer               |    s    |  F bas    |     k     |    PN 5   |
| Gauche                |    q    |  F gauche |     j     |    PN 4   |
| Droite                |    d    |  F droite |     m     |    PN 6   |
| Poser une bombe       |    f    |  espace   |  virgule  |    PN 0   |

*F: flèche
*PN: Pavé Numérique