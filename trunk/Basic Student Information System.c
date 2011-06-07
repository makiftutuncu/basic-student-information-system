/* BASIC STUDENT INFORMATION SYSTEM 1.0
 * ================================================================================
 * Pelin Öztürk & Mehmet Akif Tütüncü
 * ================================================================================
 * This project has been compiled with GNOME Compiler Collection under Ubuntu 11.04
 * ================================================================================
 * Main File
 * ================================================================================
 */

// ===== Header files =====
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"					// There are predefined macros and language strings in this header file
#include "types.h"					// There are definitions for some necessary types
// ================================================================================

// ===== Global variables =====
LINKEDLIST *students;

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

// ===== Student creation functions =====
void createAStudent()
{
	printf("\nCREATE A STUDENT\n");
	printf("==================================================\n");
	
	STUDENT newStudent;
	
	printf("Enter the name of the new student: ");
	fgets(newStudent.name, NAMELENGHT, stdin);
	newStudent.name[strlen(newStudent.name) - 1] = '\0';								// This line is to fix the name, normally after fgets function the name has an unnecessary '\n' character at the end (I obtained it by using strlen() - 1), this line replaces that with a '\0'
	
	printf("Enter id number of the new student: ");
	scanf("%d", &(newStudent.number));
	flushInput();
	
	NODE *newNode = createNode();														// Create a node as a student item for students linked list
	newNode->data = (STUDENT *) &newStudent;											// After creating the node, set the data to the newStudent variable
	addToBackLinkedList(students, newNode);												// Add the new student node to the students linked list
	
	printf("\nNew student \"%s-%d\" has been created and added to the linked list!", newStudent.name, newStudent.number);
	
	// After this we can add courses to this student. Perhaps we should create another menu function for it. (Ex: 1- Create student, 2- Add course for student, ...)
}

// ================================================================================

// ===== Menu functions =====
void printMainMenu()
{
	printf("\n%s %d.%d | %s\n", LANGUAGE_TITLE_MAINMENUBSIS, MAJORVERSION, MINORVERSION, LANGUAGE_TITLE_MAINMENU);
	printf("==================================================\n");
	printf("1- Create a student (demo)\n");
	printf("2- Exit\n\n");
	printf("%s: ", LANGUAGE_TITLE_CHOICE);
}

int evaluateMainMenu()
{
	char selection;																// Variable to hold the selection
	scanf("%c", &selection);													// Read a character as selecction
	flushInput();																// Prevent input errors
	switch(selection)															// Check the selection and direct user to neccesary function
	{
		case '1'	: createAStudent();		break;
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
	students = createLinkedList();														// Create the linked list that will hold students
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

/* I started to test creating a new student and wrote a function about it.
 * I used linked list but we can change it back to AVL tree, I just wanted to test creating a student.
 * I didn't add "ADT.h" to this even though I used it's content, because it's already added in the "types.h" file.
 * I also didn't move the strings to "macros.h" like others, because this is just a demo.
 * For now everything I added seems to be working.
 * I'll be waiting for your thoughts. =)
 *
 * mAt
 */
