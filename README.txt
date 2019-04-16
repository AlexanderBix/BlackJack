Black Jack

Author: Alexander Bix
Programming Language: C++
Operating System: Linux

Contents:
	- main.cpp: Main contents of the program
	- README: This file

Running:
	-Compile program with the following command in terminal:
		' g++ -o BlackJack main.cpp '  (Without the quotes)
	-Run program by typing './BlackJack' (Without the quotes)
	-The program will then prompt the user to enter an amount of money. The
	user starts with $100. The user cannot enter more than the amount of 
	money they currently have and the user must enter a number greater than
	0.
	-After entering the amount of money you wish to bet, the program will 
	give the user a card. Press enter to get another card or 'n' and enter 
	to stop getting cards.
	-You win if you have a card value less then or equal to 21 and if your 
	card value is greater than the dealer's card value.
	-You lose if you hav a card value greater than 21 or if your card value
	is less than the dealer's card value.
	-If you and the dealer have the same card value, it is a tie.
	-You will gain or lose the amount of money you gambled at the start 
	depending if you won or lost the round. If it is a tie, the amount of 
	money remains the same.
	-At the end of the round, a prompt comes up asking the user if they wish
	to play another round. Press 'y' and enter to continue, or 'n' and enter 
	to exit. 
	-If the player runs out of money, the game will end.

Implementation Notes:
	-This program has a heavy emphasis on randomized values. The value of a 
	card is randomized for the player and the dealer. Additionally, the 
	program tracks the amount of Ace's a person has in case the value of an
	ace needs to drop from 11 to 1.
	
Limitations:
	-The only major limitation present is that the program will crash if a 
	user enters a char/string where an int should be present. 
