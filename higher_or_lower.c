#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <stdbool.h>
#include <time.h>
#include <math.h>


void you_won_yay();
void you_lost();
void welcome() {

	printf(".----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n");
	printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
	printf("| |  ____  ____  | || |     _____    | || |    ______    | || |  ____  ____  | || |  _________   | || |  _______     | |\n");
	printf("| | |_   ||   _| | || |    |_   _|   | || |  .' ___  |   | || | |_   ||   _| | || | |_   ___  |  | || | |_   __ \\    | |\n");
	printf("| |   | |__| |   | || |      | |     | || | / .'   \\_|   | || |   | |__| |   | || |   | |_  \\_|  | || |   | |__) |   | |\n");
	printf("| |   |  __  |   | || |      | |     | || | | |   _____  | || |   |  __  |   | || |   |  _|  _   | || |   |  __ /    | |\n");
	printf("| |  _| |  | |_  | || |     _| |_    | || | \\ `.__]  _|  | || |  _| |  | |_  | || |  _| |___/ |  | || |  _| |  \\ \\_  | |\n");
	printf("| | |____||____| | || |    |_____|   | || |  `._____.'   | || | |____||____| | || | |_________|  | || | |____| |___| | |\n");
	printf("| |              | || |              | || |              | || |              | || |              | || |              | |\n");
	printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
	printf("'----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");
	printf(".----------------.  .----------------.                                                                                 \n");
	printf("| .--------------. || .--------------. |                                                                                \n");
	printf("| |     ____     | || |  _______     | |                                                                                \n");
	printf("| |   .'    `.   | || | |_   __ \\    | |                                                                                \n");
	printf("| |  /  .--.  \\  | || |   | |__) |   | |                                                                                \n");
	printf("| |  | |    | |  | || |   |  __ /    | |                                                                                \n");
	printf("| |  \\  `--'  /  | || |  _| |  \\ \\_  | |                                                                                \n");
	printf("| |   `.____.'   | || | |____| |___| | |                                                                                \n");
	printf("| |              | || |              | |                                                                                \n");
	printf("| '--------------' || '--------------' |                                                                                \n");
	printf("'----------------'  '----------------'                                                                                 \n");
	printf(".----------------.  .----------------.  .----------------.  .----------------.  .----------------.                     \n");
	printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |                    \n");
	printf("| |   _____      | || |     ____     | || | _____  _____ | || |  _________   | || |  _______     | |                    \n");
	printf("| |  |_   _|     | || |   .'    `.   | || ||_   _||_   _|| || | |_   ___  |  | || | |_   __ \\    | |                    \n");
	printf("| |    | |       | || |  /  .--.  \\  | || |  | | /\\ | |  | || |   | |_  \\_|  | || |   | |__) |   | |                    \n");
	printf("| |    | |   _   | || |  | |    | |  | || |  | |/  \\| |  | || |   |  _|  _   | || |   |  __ /    | |                    \n");
	printf("| |   _| |__/ |  | || |  \\  `--'  /  | || |  |   /\\   |  | || |  _| |___/ |  | || |  _| |  \\ \\_  | |                    \n");
	printf("| |  |________|  | || |   `.____.'   | || |  |__/  \\__|  | || | |_________|  | || | |____| |___| | |                    \n");
	printf("| |              | || |              | || |              | || |              | || |              | |                    \n");
	printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |                    \n");
	printf("'----------------'  '----------------'  '----------------'  '----------------'  '----------------'                     \n\n\n");
	printf("The rules are simple\n");
	printf("first you choose the amount of money you want to bet.\n");
	printf("then the game gives you a random number (1-100)\n");
	printf("then you choose if the deler will get a higher or lower number\n");
	printf("if you are right you win money, and if wrong you lose\n");
	printf("your goal is to become a millionner, and you dont want to go zero\n\n");
}


int get_number() {
	srand(time(NULL));
	return (rand() % 100) + 1;
}


bool play() {
	int player_number = get_number();
	printf("************\n");
	printf("Your number is: %d\n", player_number);
	printf("************\n");
	char input;

	do {
		printf("enter 'h' for higher or 'l' for lower for the next card (same number = win): ");
		// get input
		scanf_s("%c", &input, sizeof(input));
		getchar();

	} while (input != 'h' && input != 'l');
	int deler_number = get_number();
	printf("************\n");
	printf("deler number is: %d\n", deler_number);
	printf("************\n");

	if (input == 'h' && deler_number >= player_number)
	{
		return true;
	}
	else if (input == 'l' && deler_number <= player_number)
	{
		return true;
	}
	else { return false; }

}


int main(int argc, char** argv) {

	int cash = 500;
	int bet = 0;
	// print welcome
	welcome();

	// loop until win or lose
	while (cash < 1000000 && cash != 0) {
		printf("balance: %d$\n\n", cash);
		bet = 0;

		do {
			printf("enter the amount you want to bet: ");
			scanf_s("%d", &bet, sizeof(bet));
			getchar();

			if (bet > cash)
			{
				printf("\nYou cannot bet more money than you have.\n");
			}

		} while (bet > cash);
		// play round
		bool result = play();

		if (result)
		{
			cash += bet;
		}
		else { cash -= bet; }
	}
	printf("balance: %d$\n\n", cash);

	if (cash == 0)
	{
		you_lost();
	}
	else { you_won_yay(); }

	return 0;
}


void you_won_yay() {
	printf(" __     __          __          __         \n");
	printf(" \\ \\   / /          \\ \\        / /         \n");
	printf("  \\ \\_/ /__  _   _   \\ \\  /\\  / /__  _ __  \n");
	printf("   \\   / _ \\| | | |   \\ \\/  \\/ / _ \\| '_ \\ \n");
	printf("    | | (_) | |_| |    \\  /\\  / (_) | | | |\n");
	printf("    |_|\\___/ \\__,_|     \\/  \\/ \\___/|_| |_|\n");
}


void you_lost() {
	printf(" __     __           _                     \n");
	printf(" \\ \\   / /          | |                    \n");
	printf("  \\ \\_/ /__  _   _  | |     ___  ___  ___  \n");
	printf("   \\   / _ \\| | | | | |    / _ \\/ __|/ _ \\ \n");
	printf("    | | (_) | |_| | | |___| (_) \\__ \\  __/ \n");
	printf("    |_|\\___/ \\__,_| |______\\___/|___/\\___| \n");
}