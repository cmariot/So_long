#SoLong

##To do :
- [ ] Compilation on the 42 Linux Dumps
- [ ] Error if a XPM image cannot be open
- [ ] Game optimisation : previous 'C' and 'P' as new letters, update only this letter and no all '0'
- [ ] Norm
- [ ] Bonus files and Makefile bonus rule
- [ ] Enemy patrols
- [ ] Game over if hit an enemy
- [ ] Sprite animation

##Done :
- [X] Message if try to exit without all the hearts
- [X] Display a heart counter on the screen
- [X] Check the map parsing errors with valgrind
	- [X] Empty map
	- [X] Wrong extension
	- [X] The map is a directory
	- [X] Not rectangular
	- [X] No exit, no collectible or no heart on the map
	- [X] Not surronded by walls
	- [X] Unauthorized characters
	- [X] Final \n
- [X] Error on strerror
- [X] Close the window with the red cross without segfault
- [X] Display "It's a trap !" if the character try to walk on an obstacle
