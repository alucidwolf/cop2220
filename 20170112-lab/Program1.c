//Brandon Franklin
//Program 1 - Letter Guessing Game - Production

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#define MAXGUESSES 5

//void PlayOneRound(char letterFromFile);
//char GetGuess();
//int Compare(char arg1, char arg2);

//Display rules of the game
void LetterGuessGameRules(void);

//Play a round with the letter from the file
void PlayOneRound(char letterFromFile);

//Get the user's guess for the game
char GetGuess(void);

//Compare the user guess and the letter pulled from the file
int CompareCharacters(char letterFromFile, char guessFromUser);

//Giving a hint to the user
void GiveHint(int win, char uppUserGuess, char letterFromFile, int numGuesses);

//Dotted line function for formatting
void printDotLine();

int main()
{
	//declare FILE pointer
	FILE * fPointer1;

	//number of games and loop variables
	int numGames, i = 0;

	//letter from file variables
	char letter;

				//display game rules
	LetterGuessGameRules();

				//Ask and get number of games to play
	printf("How many games are we gonna play today? 10 or less please, I got things to compile.\n");
	scanf("%d", &numGames);
	printf("You chose to play %d games. Awesome!\n\n", numGames);

				//connect to the file HINT: use fopen
	fPointer1 = fopen("letters.txt", "r");

				//this for loop will allow the player to play more than one game
				//without recompiling
	for (i = 0; i < numGames; i++)
	{
		printf("Let's play game #%d.\n", i + 1);

		//get a solution letter from file - use fscanf
		fscanf(fPointer1, " %c", &letter);

		//change the solution to uppercase
		char uppLetter = toupper(letter);		
		
		//print the solution back onto the screen to test
		//printf("This is the letter from the file: %c\n", uppLetter);

		//call the PlayOneRound function and pass it the solution
		PlayOneRound(uppLetter);		

	}
	printf("\nYou have no more games left to play.\n\nSee you next time.\n\n");

	//close file pointer
	fclose(fPointer1);
	return 0;
}//end main

//this function runs one game. 
//input: character from the file
//void return type
//all other functions to Play one round of a game 
//are called from within the PlayOneRound function
void PlayOneRound(char letterFromFile)
{
	//initialize and declare some variables
	int win = 0, numGuesses = 0;
	char userGuess, uppUserGuess;


	while (numGuesses < MAXGUESSES && win == 0)
	{
		printf("\nYou are on guess %d of %d.\n", numGuesses + 1, MAXGUESSES);

		//get a guess from the user  by calling the GetGuess function
		userGuess = GetGuess();

		//change the guess to uppercase
		uppUserGuess = toupper(userGuess);

		//win = call the function to compare the guess with the solution
		win = CompareCharacters(letterFromFile, uppUserGuess);

		//give the user a hint based of the result of the comparison function
		GiveHint(win, uppUserGuess, letterFromFile, numGuesses);		

		//count the number of guesses so far
		numGuesses++;
	}
	//use conditions to let the user know if they won or lost the round of the game

};

//Displays the rules of the game
void LetterGuessGameRules() {
	printf("\n( '_')0*´¯`·. Welcome to the Letter Guessing Game! .·´¯`°Q('_' )\n\nI am going to ask you how many games you want to play, then we will start guessing letters.\n\nYou only get 5 guesses each game or else I win!\n\nReady when you are.\n\n");
};

//Gets the guess from the user and returns the value so we can use later
char GetGuess() {
	char ug;
	printf("Give me your best guess, a letter => ");
	scanf(" %c", &ug);
	return ug;
};

//Compares the guess we stored from the user to the letter we got from the file
int CompareCharacters(char letterFromFile, char guessFromUser) {
	if (letterFromFile != guessFromUser)
		return 0;
		return 1;
};

//Accept all variables and give the user a hint based on that info
void GiveHint(int win, char uppUserGuess, char letterFromFile, int numGuesses) {
	//tell them they won
	if (win == 1) {
		printDotLine();
		printf("\n( '_')0*´¯`·.¸.·´¯`°Q('_' )( '_')0*´¯`·.¸.·´¯`°Q('_' )( '_')0*´¯`·.¸.·´¯`°Q('_' )\n\n                YOU WIN! OMG FEELSGOODMAN #hashtags #memes.\n\n( '_')0*´¯`·.¸.·´¯`°Q('_' )( '_')0*´¯`·.¸.·´¯`°Q('_' )( '_')0*´¯`·.¸.·´¯`°Q('_' )\n");
		printDotLine();
	}
	//tell them they have no more guesses left
	else if (numGuesses == 4) {
		printDotLine();
		printf("That was your last guess and it was wrong, sorry. The answer was %c. So ... I WIN! #dankmemes #winning", letterFromFile);
		printDotLine();
	}
	//tell them their guess is before the solution
	else if (uppUserGuess < letterFromFile) {
		printDotLine();
		printf("**Family Feud Buzzer Sound**\nYour guess was: %char. The answer comes AFTER your guess in the alphabet.", uppUserGuess);
		//add last guess incentive
		if (numGuesses == 3) {
			printf("..the American one, come one now there are only 26 possibilities.");
		}
		printDotLine();
	}
	//tell them their guess is after the solution
	else {
		printDotLine();
		printf("**Family Feud Buzzer Sound**\nYour guess was: %c. The answer comes BEFORE your guess in the alphabet.", uppUserGuess);
		//add last guess incentive
		if (numGuesses == 3) {
			printf("..the American one, come one now there are only 26 possibilities.");
		}
		printDotLine();
	}
};

void printDotLine() {
	printf("\n-----------------------------------\n");
};
