/* BASIC STUDENT INFORMATION SYSTEM 1.0
 * ================================================================================
 * Pelin Öztürk & Mehmet Akif Tütüncü
 * ================================================================================
 * This project has been compiled with GNOME Compiler Collection under Ubuntu 11.04
 * ================================================================================
 * Main file
 * ================================================================================
 */

// ===== Header files =====
#include <stdio.h>
#include <stdlib.h>
#include "macros.h"					// There are predefined macros and language strings in this header file
// ================================================================================

// ===== General functions =====
void flushInput()					// This function is to prevent the application from buffer errors during user input through terminal
{
	int c = 999;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}
// ================================================================================

// ===== Menu functions =====
void printMainMenu()
{
	printf("\n%s %d.%d | %s\n", LANGUAGE_TITLE_MAINMENUBSIS, MAJORVERSION, MINORVERSION, LANGUAGE_TITLE_MAINMENU);
	printf("==================================================\n");
	printf("1- \n");
	printf("2- \n\n");
	printf("%s: ", LANGUAGE_TITLE_CHOICE);
}

int evaluateMainMenu()
{
	char selection;																// Variable to hold the selection
	scanf("%c", &selection);													// Read a character as selecction
	flushInput();																// Prevent input errors
	switch(selection)															// Check the selection and direct user to neccesary function
	{
		case '1'	: break;
		case '2'	: exit(0);													// User wanted to exit, exit the application, so the infinite loop in main function is over
		default		:															// User entered something that was not one of the possible options, show error and to indicate that there was an error return -1 to main function
			printf("\n==================================================\n");
			printf("%s\n", LANGUAGE_TITLE_INPUTERROR);
			printf("==================================================\n");
			printMainMenu();													// Print the main menu again
			return -1;
	}
}
// ================================================================================

// ===== Main function =====
int main()
{
	int result = 0;																		// Variable to hold result of main menu evaluation
	printMainMenu();																	// Print main menu
	while(1)																			// Start an infinite loop (unless user wants to exit, continue)
	{
		result = evaluateMainMenu();													// Get a result from main menu evaluation
		if(result == -1)																// If the result was -1
		{
			continue;																	// User entered something wrong and an error is shown, continue
		}
		printf("\n=========== %s ===========\n", LANGUAGE_TITLE_RETURNTOMAINMENU);		// A correct selection was made and the process has been finished, return to main menu
		printMainMenu();																// Print main menu again
	}
	return 0;
}
