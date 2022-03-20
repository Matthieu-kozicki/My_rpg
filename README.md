# MUL_my_rpg (Epitech Project 2018)

![Welcome](https://github.com/yoansj/MUL_my_rpg/blob/master/pictures/logo.png)

* Welcome to the Pokemon Fusions repository !
* Follow all the steps below if you want to play the game

 ### For Epitech Students
* Do not copy this project or even part of the code
* It would be stupid to get a -42 for one of the biggest project of the year

## Installation
* This game was made using the CSFML library, it won't compile without it
[(How to install the library)](https://www.sfml-dev.org/download/csfml/index-fr.php)
* Clone the repository
* Go to the root of the repository
```bash
make re
./my_rpg
```
## How to play

* Hold your click on the ? button on the menu then you should see the image below
![Image](https://github.com/yoansj/MUL_my_rpg/blob/master/gitimages/how_to_play.png)
* Click on the options button if you want to change de keybindings or lower the sound
![Image](https://github.com/yoansj/MUL_my_rpg/blob/master/gitimages/options.png)

## Combat
* Unlike other Pokemon games the combat is not turn by turn
* You have to hold Enter and select Attack to make your Pokemon Attack
* Be careful if your Pokemon dies, it's game over !
![Image](https://github.com/yoansj/MUL_my_rpg/blob/master/gitimages/combat.png)

## Customize the game !
* Here you will learn how to put your own Pokemon into the game
* Pokemons stats are kept in files in the pokemons/ directory

Here is the example file for a Pokemon
```
[START]
[NAME]
[ATTACK NAME]
[PATH_TO_SPRITE]
[PATH_TO_ATTACK]
[TYPE][1:FIRE][2:WATER][3:ELECTR][4:NORMAL][5:ROCK][6:LEAF]
[HP]
[DMG]
[DEFENSE]
[PRICE]
[END]
```
* The ```[START]``` and ```[END]``` lines are mandatory ! Without them the game won't read your file !

For instance the Pokemon Pikaflex will give this file
```
[START]
Pikaflex
Ultra FLEX
pictures/Poke/Pikaflex.bmp
pictures/Poke/Pikaflex.bmp
3
80
25
2
900
[END]
```
In game it will look like this
![Image](https://github.com/yoansj/MUL_my_rpg/blob/master/gitimages/pikaflex.png)

 * Be careful with the paths entering wrong ones will create errors
 * The ```[PATH_TO_ATTACK]``` line isn't used by the game but you still have to enter a valid one
 * You can balance your game how you want by modifying, deleting or event creating new Pokemons !
 * If you want to add consistent Pokemons use the [Pokemon Fusion generator](https://pokemon.alexonsager.net/fr)
 
 ## Authors
 * Matthieu Kozicki -> Menus, Inventory, Options
 * Yoan Saint Juste -> Combat, Pokemons, Particles
 * Vincent Maillot -> Collisions & Map, Movement, Sprites
 * Grade : 209
 
