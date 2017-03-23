// Brandon Franklin
// COP2220
// Banking Program - Program2.c

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<ctype.h>
#define CREDITLIMIT 3000

void MakeTransaction(char *againPtr);
void DisplayBalance(double checking, double savings, double credit);
void RunChoices(int *choicePtr);
void SelectAccount(char *accountPtr);
void AddMoney(double *moneyPtr);
void RemoveMoney(double *moneyPtr, char account);
void PrintLine();

int main() {
	int choice;
	double check = 800.00, sav = 800.00, cred = (-700.00), money;
	char proceed, account;	

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	/* Save current attributes */
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("Welcome to the Bank of Penguins!\n\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);
	printf("**Please open console window FULL WIDTH to get the best experience!**\n\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("                                                          $$$$\\  \n");
	printf("                                                         $$  $$\\ \n");
	printf("$$$$$$\\$$$$\\   $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\   $$$$$$$\\\\__/$$ |\n");
	printf("$$  _$$  _$$\\ $$  __$$\\ $$  _$$  _$$\\ $$  __$$\\ $$  _____|  $$  |\n");
	printf("$$ / $$ / $$ |$$$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |\\$$$$$$\\   $$  / \n");
	printf("$$ | $$ | $$ |$$   ____|$$ | $$ | $$ |$$   ____| \\____$$\\  \\__/  \n");
	printf("$$ | $$ | $$ |\\$$$$$$$\\ $$ | $$ | $$ |\\$$$$$$$\\ $$$$$$$  | $$\\   \n");
	printf("\\__| \\__| \\__| \\_______|\\__| \\__| \\__| \\_______|\\_______/  \\__|  \n");

	SetConsoleTextAttribute(hConsole, saved_attributes);

	do {
		DisplayBalance(check, sav, cred); // pass by copy

		RunChoices(&choice); // pass by address (1 for DEPOSIT, 2 for WITHDRAW)

		SelectAccount(&account); // pass by address

		switch (choice) {
		case 1: // DEPOSIT			
			if (account == 'c') {
				AddMoney(&check);
			}
			else if (account == 's') {
				AddMoney(&sav);
			}
			else if (account = 'r') {
				AddMoney(&cred);
			}
			else {
				printf("Not recongnized!\n");
			}
			DisplayBalance(check, sav, cred);
			break;
		case 2: // WITHDRAW			
			if (account == 'c') {
				RemoveMoney(&check, account);
			}
			else if (account == 's') {
				RemoveMoney(&sav, account);
			}
			else if (account = 'r') {
				RemoveMoney(&cred, account);
			}
			else {
				printf("Not recongnized!\n");
			}
			DisplayBalance(check, sav, cred);
			break;
		default:
			printf("Press 1 or 2 please!\n");
		};

		MakeTransaction(&proceed); // pass by address		

	} while (proceed == 'y');

	PrintLine();
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	printf("   /$$     /$$                           /$$                                      \n");    
	printf("  | $$    | $$                          | $$                                          \n");
	printf(" /$$$$$$  | $$$$$$$   /$$$$$$  /$$$$$$$ | $$   /$$       /$$   /$$  /$$$$$$  /$$   /$$\n");
	printf("|_  $$_/  | $$__  $$ |____  $$| $$__  $$| $$  /$$/      | $$  | $$ /$$__  $$| $$  | $$\n");
	printf("  | $$    | $$  \\ $$  /$$$$$$$| $$  \\ $$| $$$$$$/       | $$  | $$| $$  \\ $$| $$  | $$\n");
	printf("  | $$ /$$| $$  | $$ /$$__  $$| $$  | $$| $$_  $$       | $$  | $$| $$  | $$| $$  | $$\n");
	printf("  |  $$$$/| $$  | $$|  $$$$$$$| $$  | $$| $$ \\  $$      |  $$$$$$$|  $$$$$$/|  $$$$$$/\n");
	printf("   \\___/  |__/  |__/ \\_______/|__/  |__/|__/  \\__/       \\____  $$ \\______/  \ \______/ \n");
	printf("                                                         /$$  | $$                    \n");
	printf("                                                        |  $$$$$$/                    \n");
	printf("                                                         \\______/                     ");
	SetConsoleTextAttribute(hConsole, saved_attributes);
	PrintLine();

	return 0;
};

//Asks if they want another transaction
//sets the value of againPtr to (y or n)
void MakeTransaction(char *proceedPtr) {
	printf("Would you like to make a transaction?(y or n) => ");
	scanf(" %c", proceedPtr);
	*proceedPtr = tolower(*proceedPtr);
};

//Displays the user’s current account balance for all three accounts
void DisplayBalance(double checking, double savings, double credit) {
	PrintLine();
	printf("Your current account balances:\n");
	printf("	Checking => %.2f\n", checking);
	printf("	Savings => %.2f\n", savings);
	printf("	Credit => %.2f\n", credit);
	PrintLine();
};

// Displays the list of integer options available
//prompts for the user’s choice and sets the value of the choicePtr
void RunChoices(int *choicePtr) {
	printf("Would you like to make a Deposit(1) or a Withdraw(2)?\nEnter(1 or 2) => ");
	scanf("%d", choicePtr);
	PrintLine();
};

//Asks the user which type of account they would like to access and sets the
//value of the the character accountPtr
void SelectAccount(char *accountPtr) {
	printf("Which account would you like to access?\n(C) Checking\n(S) Savings\n(R) Credit\n");
	scanf(" %c", accountPtr);
	*accountPtr = tolower(*accountPtr);
	printf("You chose to access: %c\n", *accountPtr);
	PrintLine();
};

//Prompts the user for the amount to deposit
//and adds that value to the amount in the bank account
void AddMoney(double *moneyPtr) {
	double userAddMoney;	
	printf("How much would you like to add?\nEnter => ");
	scanf("%lf", &userAddMoney);
	*moneyPtr = *moneyPtr + userAddMoney;	
};

//Prompts the user for the amount of the withdrawal, determines if there are
//sufficient funds and updates the selected account if funds are dispensed
void RemoveMoney(double *moneyPtr, char account) { // &check, &sav, &cred or 'c', 's', 'r'
	if (account == 'c') {
		// cannot go below zero
		double userRemoveMoney;
		printf("How much would you like to withdraw from your checking account?\nIt currently has: $%.2f\nEnter => ", *moneyPtr);
		scanf("%lf", &userRemoveMoney);
		if (userRemoveMoney > *moneyPtr) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
			WORD saved_attributes;
			/* Save current attributes */
			GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
			saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);			
			printf(" __      __                                                             __                            __                  __ \n");
			printf("/  \\    /  |                                                           /  |                          /  |                /  |\n");
			printf("$$  \\  /$$/______   __    __         ______    ______    ______        $$ |____    ______    ______  $$ |   __   ______  $$ |\n");
			printf(" $$  \\/$$//      \\ /  |  /  |       /      \\  /      \\  /      \\       $$      \\  /      \\  /      \\ $$ |  /  | /      \\ $$ |\n");
			printf("  $$  $$//$$$$$$  |$$ |  $$ |       $$$$$$  |/$$$$$$  |/$$$$$$  |      $$$$$$$  |/$$$$$$  |/$$$$$$  |$$ |_/$$/ /$$$$$$  |$$ |\n");
			printf("   $$$$/ $$ |  $$ |$$ |  $$ |       /    $$ |$$ |  $$/ $$    $$ |      $$ |  $$ |$$ |  $$/ $$ |  $$ |$$   $$<  $$    $$ |$$/ \n");
			printf("    $$ | $$ \\__$$ |$$ \\__$$ |      /$$$$$$$ |$$ |      $$$$$$$$/       $$ |__$$ |$$ |      $$ \\__$$ |$$$$$$  \\ $$$$$$$$/  __ \n");
			printf("    $$ | $$    $$/ $$    $$/       $$    $$ |$$ |      $$       |      $$    $$/ $$ |      $$    $$/ $$ | $$  |$$       |/  |\n");
			printf("    $$/   $$$$$$/   $$$$$$/         $$$$$$$/ $$/        $$$$$$$/       $$$$$$$/  $$/        $$$$$$/  $$/   $$/  $$$$$$$/ $$/ \n");
			SetConsoleTextAttribute(hConsole, saved_attributes);
		}
		else {
			*moneyPtr = *moneyPtr - userRemoveMoney;
			printf("new amount is: %.2f\n", *moneyPtr);
		}
	}
	else if (account == 's') {
		// cannot go below zero
		double userRemoveMoney;
		printf("How much would you like to withdraw from your saving account?\nIt currently has: $%.2f\nEnter => ", *moneyPtr);
		scanf("%lf", &userRemoveMoney);
		if (userRemoveMoney > *moneyPtr) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
			WORD saved_attributes;
			/* Save current attributes */
			GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
			saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			printf(" __      __                                                             __                            __                  __ \n");
			printf("/  \\    /  |                                                           /  |                          /  |                /  |\n");
			printf("$$  \\  /$$/______   __    __         ______    ______    ______        $$ |____    ______    ______  $$ |   __   ______  $$ |\n");
			printf(" $$  \\/$$//      \\ /  |  /  |       /      \\  /      \\  /      \\       $$      \\  /      \\  /      \\ $$ |  /  | /      \\ $$ |\n");
			printf("  $$  $$//$$$$$$  |$$ |  $$ |       $$$$$$  |/$$$$$$  |/$$$$$$  |      $$$$$$$  |/$$$$$$  |/$$$$$$  |$$ |_/$$/ /$$$$$$  |$$ |\n");
			printf("   $$$$/ $$ |  $$ |$$ |  $$ |       /    $$ |$$ |  $$/ $$    $$ |      $$ |  $$ |$$ |  $$/ $$ |  $$ |$$   $$<  $$    $$ |$$/ \n");
			printf("    $$ | $$ \\__$$ |$$ \\__$$ |      /$$$$$$$ |$$ |      $$$$$$$$/       $$ |__$$ |$$ |      $$ \\__$$ |$$$$$$  \\ $$$$$$$$/  __ \n");
			printf("    $$ | $$    $$/ $$    $$/       $$    $$ |$$ |      $$       |      $$    $$/ $$ |      $$    $$/ $$ | $$  |$$       |/  |\n");
			printf("    $$/   $$$$$$/   $$$$$$/         $$$$$$$/ $$/        $$$$$$$/       $$$$$$$/  $$/        $$$$$$/  $$/   $$/  $$$$$$$/ $$/ \n");
			SetConsoleTextAttribute(hConsole, saved_attributes);
		}
		else {
			*moneyPtr = *moneyPtr - userRemoveMoney;			
		}
	}
	else if (account == 'r') {
		// cannot go below the credit limit -3000
		double userRemoveMoney;
		double moneyPtrCompare;
		double displayCredit;
		displayCredit = *moneyPtr + CREDITLIMIT;
		printf("How much would you like to withdraw from your credit account?\nYou can withdraw $%.2f more before you hit your $3000 limit.\nEnter => ", displayCredit);
		scanf("%lf", &userRemoveMoney);
		moneyPtrCompare = CREDITLIMIT + *moneyPtr;		
		if (userRemoveMoney > moneyPtrCompare) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
			WORD saved_attributes;
			/* Save current attributes */
			GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
			saved_attributes = consoleInfo.wAttributes;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			printf(" __      __                                                             __                            __                  __ \n");
			printf("/  \\    /  |                                                           /  |                          /  |                /  |\n");
			printf("$$  \\  /$$/______   __    __         ______    ______    ______        $$ |____    ______    ______  $$ |   __   ______  $$ |\n");
			printf(" $$  \\/$$//      \\ /  |  /  |       /      \\  /      \\  /      \\       $$      \\  /      \\  /      \\ $$ |  /  | /      \\ $$ |\n");
			printf("  $$  $$//$$$$$$  |$$ |  $$ |       $$$$$$  |/$$$$$$  |/$$$$$$  |      $$$$$$$  |/$$$$$$  |/$$$$$$  |$$ |_/$$/ /$$$$$$  |$$ |\n");
			printf("   $$$$/ $$ |  $$ |$$ |  $$ |       /    $$ |$$ |  $$/ $$    $$ |      $$ |  $$ |$$ |  $$/ $$ |  $$ |$$   $$<  $$    $$ |$$/ \n");
			printf("    $$ | $$ \\__$$ |$$ \\__$$ |      /$$$$$$$ |$$ |      $$$$$$$$/       $$ |__$$ |$$ |      $$ \\__$$ |$$$$$$  \\ $$$$$$$$/  __ \n");
			printf("    $$ | $$    $$/ $$    $$/       $$    $$ |$$ |      $$       |      $$    $$/ $$ |      $$    $$/ $$ | $$  |$$       |/  |\n");
			printf("    $$/   $$$$$$/   $$$$$$/         $$$$$$$/ $$/        $$$$$$$/       $$$$$$$/  $$/        $$$$$$/  $$/   $$/  $$$$$$$/ $$/ \n");
			SetConsoleTextAttribute(hConsole, saved_attributes);
		}
		else {
			*moneyPtr = *moneyPtr - userRemoveMoney;			
		}
	}
};

void PrintLine() {
	printf("\n--------------------------------------------\n\n");
};
